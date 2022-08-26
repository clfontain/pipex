/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:12:34 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/04 11:42:20 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_command(t_data *data, char *str)
{
	data->command = ft_split(str, ' ');
	if (data->command == NULL)
	{
		ft_printf_error("Error\nMalloc failed\n");
		return (1);
	}	
	return (0);
}

void	init_data(t_data *data)
{
	data->command = NULL;
	data->command_path = NULL;
	data->new_argv = NULL;
	data->fdfile = 0;
	data->file_name = NULL;
}

void	init(t_pipex *pipex)
{
	pipex->pathstr = NULL;
	pipex->path = NULL;
	init_data(&pipex->data1);
	init_data(&pipex->data2);
}
