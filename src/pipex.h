/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:54:27 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/19 14:54:31 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

/* from utils.c */
int		check_access(char *infile, char *outfile);
char	*get_path(char **envp);
int		free_cmds(char **cmd1, char **cmd2);
/* from pipex.c */
void	exec_cmd1(int *fd, int input, char **cmd1, char **envp);
void	exec_cmd2(int *fd, int output, char **cmd2, char **envp);
void	pipex(int *in_out, char **cmd1, char **cmd2, char **envp);

#endif
