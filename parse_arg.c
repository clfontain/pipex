/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:28:14 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/04 11:28:33 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_absolute_path2(char *str)
{
	int		i;
	char	**new_argv;

	i = 0;
	new_argv = NULL;
	new_argv = malloc(sizeof(char *) * 2);
	if (new_argv == NULL)
		return (NULL);
	i = (ft_strlen(str) - 1);
	while (str[i] != '/')
		i--;
	i++;
	new_argv[0] = NULL;
	new_argv[1] = NULL;
	new_argv[0] = ft_strdup(str + i);
	if (new_argv[0] == NULL)
		return (destroy_str(new_argv), NULL);
	return (new_argv);
}

int	parse_absolute_path(t_data *data, char *str)
{
	data->command = parse_absolute_path2(str);
	if (data->command == NULL)
		return (ft_printf_error("Malloc Error\n"), 1);
	data->command_path = ft_strdup(str);
	if (data->command_path == NULL)
		return (ft_printf_error("Malloc Error\n"), 1);
	if (access(data->command_path, F_OK) != 0)
		return (ft_printf_error("Access failed \n"), 1);
	return (0);
}

int	parse_with_env2(t_pipex *pipex, char **argv, char **env)
{
	if (pipex->pathstr == NULL)
	{
		pipex->pathstr = return_path(env);
		if (pipex->pathstr == NULL)
			return (1);
	}
	if (pipex->path == NULL)
	{		
		pipex->path = return_env(pipex->pathstr);
		if (pipex->path == NULL)
			return (1);
	}
	if (init_command(&pipex->data2, argv[3]) == 1)
		return (1);
	pipex->data2.command_path = ft_check_path(pipex->path, &pipex->data2);
	if (pipex->data2.command_path == NULL)
		return (1);
	return (0);
}

int	parse_with_env1(t_pipex *pipex, char **argv, char **env)
{
	if (pipex->pathstr == NULL)
	{
		pipex->pathstr = return_path(env);
		if (pipex->pathstr == NULL)
			return (1);
	}
	if (pipex->path == NULL)
	{		
		pipex->path = return_env(pipex->pathstr);
		if (pipex->path == NULL)
			return (1);
	}
	if (init_command(&pipex->data1, argv[2]) == 1)
		return (1);
	pipex->data1.command_path = ft_check_path(pipex->path, &pipex->data1);
	if (pipex->data1.command_path == NULL)
		return (1);
	return (0);
}			

int	parse_arg(t_pipex *pipex, char **argv, char **env)
{
	if ((argv[2][0] == '/') | (argv[2][0] == '.'))
	{
		if (parse_absolute_path(&pipex->data1, argv[2]) == 1)
			return (1);
	}
	else
	{
		if (parse_with_env1(pipex, argv, env) == 1)
			return (1);
	}
	if ((argv[3][0] == '/') | (argv[3][0] == '.'))
	{
		if (parse_absolute_path(&pipex->data2, argv[3]) == 1)
			return (1);
	}
	else
	{
		if (parse_with_env2(pipex, argv, env) == 1)
			return (1);
	}
	return (0);
}
