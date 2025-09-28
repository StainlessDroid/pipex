/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:54:27 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/26 13:54:02 by mapascua         ###   ########.fr       */
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
void	try_paths(char **cmd, char **envp);
char	*get_path(char **envp);
void	close_streams(int *in_out, int *pipe);
/* from pipex.c */
int		pipex(int *in_out, int *pipe, char **argv, char **envp);
void	pipex_start(int *in_out, int *pipe, char **argv, char **envp);
void	pipex_end(int *in_out, int *pipe, char **argv, char **envp);
#endif
