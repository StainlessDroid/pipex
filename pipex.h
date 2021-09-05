/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:45:40 by mpascual          #+#    #+#             */
/*   Updated: 2021/09/05 02:16:59 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf/header.h"
#include <sys/wait.h>
#include <stdio.h>

int     check_access(char *infile, char *outfile);
char    *get_path(char **envp);
void    exec_cmd1(int *fd, int input, char **cmd1, char **envp);
void    exec_cmd2(int *fd, int output, char **cmd2, char **envp);
void    pipex(int input, int output, char **cmd1, char **cmd2, char **envp);