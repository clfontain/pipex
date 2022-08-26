/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:10:43 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/04 11:43:59 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_data
{
	char	**command;
	char	*command_path;
	char	**new_argv;
	char	*file_name;
	int		fdfile;
}			t_data;

typedef struct s_pipex
{
	t_data	data1;
	t_data	data2;
	char	*pathstr;
	char	**path;
	int		pipes[2];
}			t_pipex;

int		ft_open_files(t_pipex *pipex);

char	*ft_check_path(char **path, t_data *data);
char	**return_env(char *str);
char	*return_path(char **env);

void	destroy_all(t_pipex *pipex);
void	destroy_str(char **str);
void	destroy_data(t_data data);

int		ft_fork(t_pipex *pipex, char **env);
int		ft_child1(t_pipex *pipex, char **env);
int		ft_child2(t_pipex *pipex, char **env);

void	init(t_pipex *pipex);
void	init_data(t_data *data);
int		init_command(t_data *data, char *str);

char	*str_triple_join(char *s1, char *s2);

int		parse_arg(t_pipex *pipex, char **argv, char **env);
char	**parse_absolute_path2(char *str);
int		parse_absolute_path(t_data *data, char *str);
int		parse_with_env2(t_pipex *pipex, char **argv, char **env);
int		parse_with_env1(t_pipex *pipex, char **argv, char **env);

#endif