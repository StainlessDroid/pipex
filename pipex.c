/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:13:35 by mpascual          #+#    #+#             */
/*   Updated: 2021/09/02 12:03:12 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf/header.h"
#include <sys/wait.h>
#include <stdio.h>

void    pipex(int input, int output, char **cmd1, char **cmd2, char **envp)
{
    int   fd[2];
    int   status;
    pid_t child1;
    pid_t child2;

    status = 0;
    if (pipe(fd) != 0)
        perror("Error");
    child1 = fork();
    if (child1 < 0)
        perror("Fork: ");
    if (child1 == 0)
    {
        dup2(fd[1], 1);
        dup2(input, 0);
        close(fd[0]);
        close(fd[1]);
        execve(ft_strjoin("/usr/bin/", cmd1[0]), cmd1, envp);
        perror("Error");
    }
    child2 = fork();
    if (child2 < 0)
        perror("Fork: ");
    if (child2 == 0)
    {
        dup2(fd[0], 0);
        dup2(output, 1);
        close(fd[0]);
        close(fd[1]);
        execve(ft_strjoin("/usr/bin/", cmd2[0]), cmd2, envp);
        perror("Error");
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, &status, 0);  // supervising the children
    waitpid(-1, &status, 0);  // while they finish their tasks
}

int     check_access(char *infile, char *outfile)
{
    if (access(infile, R_OK) != 0)
    {
        perror("input.txt : Reading permission denied");
        return (EXIT_FAILURE);
    }
    if (access(outfile, W_OK) != 0)
    {
        perror("output.txt : Writing permission denied");
        return (EXIT_FAILURE);
    }
    else
        return (EXIT_SUCCESS);
}

int     main(int argc, char **argv, char **envp)
{
    int     in_fd;
    int     out_fd;
    char    **cmd_arg1;
    char    **cmd_arg2;

    if (argc == 5)
    {
        cmd_arg1 = ft_split(argv[2], ' ');
        cmd_arg2 = ft_split(argv[3], ' ');
        if (check_access(argv[1], argv[4]) != 0)
            exit(EXIT_FAILURE);
        else
        {
            in_fd = open(argv[1], O_RDONLY);
            out_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
        }
        pipex(in_fd, out_fd, cmd_arg1, cmd_arg2, envp);
    }
    else
        exit(EXIT_FAILURE);
    return (0);
}