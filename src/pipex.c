/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:13:35 by mpascual          #+#    #+#             */
/*   Updated: 2021/09/06 10:27:54 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd1(int *fd, int input, char **cmd1, char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	paths = ft_split(get_path(envp), ':');
	dup2(fd[1], 1);
	dup2(input, 0);
	close(fd[0]);
	close(fd[1]);
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		execve(ft_strjoin(paths[i], cmd1[0]), cmd1, envp);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	exec_cmd2(int *fd, int output, char **cmd2, char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	paths = ft_split(get_path(envp), ':');
	dup2(fd[0], 0);
	dup2(output, 1);
	close(fd[0]);
	close(fd[1]);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		execve(ft_strjoin(paths[i], cmd2[0]), cmd2, envp);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	pipex(int *in_out, char **cmd1, char **cmd2, char **envp)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;
	int		status;

	status = 0;
	if (pipe(fd) != 0)
		perror("Error");
	child1 = fork();
	if (child1 < 0)
		perror("Fork: ");
	if (child1 == 0)
		exec_cmd1(fd, in_out[0], cmd1, envp);
	child2 = fork();
	if (child2 < 0)
		perror("Fork: ");
	if (child2 == 0)
		exec_cmd2(fd, in_out[1], cmd2, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_out[2];
	char	**cmd_arg1;
	char	**cmd_arg2;

	if (argc == 5)
	{
		cmd_arg1 = ft_split(argv[2], ' ');
		cmd_arg2 = ft_split(argv[3], ' ');
		if (check_access(argv[1], argv[4]) != 0)
			exit(EXIT_FAILURE);
		else
		{
			in_out[0] = open(argv[1], O_RDONLY);
			in_out[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		}
		pipex(in_out, cmd_arg1, cmd_arg2, envp);
	}
	else
	{
		perror("Wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}
