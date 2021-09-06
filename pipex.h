/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:45:40 by mpascual          #+#    #+#             */
/*   Updated: 2021/09/06 10:24:09 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		check_access(char *infile, char *outfile);
char	*get_path(char **envp);
void	exec_cmd1(int *fd, int input, char **cmd1, char **envp);
void	exec_cmd2(int *fd, int output, char **cmd2, char **envp);
void	pipex(int *in_out, char **cmd1, char **cmd2, char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);

#endif