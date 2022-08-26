/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:02:42 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/02 13:47:05 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	destroy_str(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free (str[i]);
			i++;
		}
		free (str);
	}	
}

void	destroy_data(t_data data)
{
	if (data.command)
		destroy_str(data.command);
	if (data.command_path)
		free (data.command_path);
	if (data.new_argv)
		destroy_str(data.new_argv);
}

void	destroy_all(t_pipex *pipex)
{
	if (pipex->path)
		destroy_str(pipex->path);
	destroy_data(pipex->data1);
	destroy_data(pipex->data2);
}
