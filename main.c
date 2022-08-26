/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:07:41 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/04 11:34:07 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_files(t_pipex *pipex)
{
	pipex->data1.fdfile = open(pipex->data1.file_name, O_RDONLY);
	if (pipex->data1.fdfile == -1)
		return (ft_printf_error("Error open infile\n"), 1);
	pipex->data2.fdfile = open(pipex->data2.file_name, O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (pipex->data2.fdfile == -1)
	{
		close(pipex->data1.fdfile);
		return (ft_printf_error("Error open outfile\n"), 1);
	}	
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf_error("Error\nInvalid arguments\n"), 1);
	init(&pipex);
	pipex.data1.file_name = argv[1];
	pipex.data2.file_name = argv[4];
	if (parse_arg(&pipex, argv, env) == 1)
		return (destroy_all(&pipex), 1);
	if (ft_open_files(&pipex) == 1)
		return (destroy_all(&pipex), 1);
	if (pipe(pipex.pipes) != 0)
	{
		destroy_all(&pipex);
		ft_printf_error("Error pipe init\n");
		return (close (pipex.data1.fdfile), close (pipex.data2.fdfile), 1);
	}
	if (ft_fork(&pipex, env) == 1)
		return (destroy_all(&pipex), 1);
	destroy_all(&pipex);
	return (0);
}
