/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:55:55 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/04 11:19:34 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_path(char **path, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (path[i] != NULL)
	{
		if (!path[i] | !data->command[0])
			return (ft_printf_error("Error\nCommand not found\n"), NULL);
		str = str_triple_join(path[i], data->command[0]);
		if (str == NULL)
			return (ft_printf_error("Malloc Error\n"), NULL);
		if (access(str, F_OK) == 0)
			return (str);
		free (str);
		i++;
	}
	return (ft_printf_error("No valid path found\n"), NULL);
}

char	**return_env(char *str)
{
	char	**path;

	path = ft_split(str + 5, ':');
	if (path == NULL)
		return (ft_printf_error("Malloc Error\n"), NULL);
	return (path);
}

char	*return_path(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			return (env[i]);
		i++;
	}	
	return (ft_printf_error("Error\nNo valid path found\n"), NULL);
}
