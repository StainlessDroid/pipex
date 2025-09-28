/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:43:32 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/26 18:03:54 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(int *in_out, int *pipefd, char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	if (!cmd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (cmd[0] == NULL)
	{
		ft_free("d", cmd);
		exit(EXIT_FAILURE);
	}
	dup2(in_out[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close_streams(in_out, pipefd);
	try_paths(cmd, envp);
	ft_free("d", cmd);
	exit(EXIT_FAILURE);
}

void	pipex_end(int *in_out, int *pipefd, char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv[3], ' ');
	if (!cmd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (cmd[0] == NULL)
	{
		ft_free("d", cmd);
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(in_out[1], STDOUT_FILENO);
	close_streams(in_out, pipefd);
	try_paths(cmd, envp);
	ft_free("d", cmd);
	exit(EXIT_FAILURE);
}

int	pipex(int *in_out, int *pipefd, char **argv, char **envp)
/* Create a child for each command executed and wait until both
 * processes end */
{
	pid_t	child1;
	pid_t	child2;

	child1 = fork();
	if (child1 < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (child1 == 0)
		pipex_start(in_out, pipefd, argv, envp);
	child2 = fork();
	if (child2 < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (child2 == 0)
		pipex_end(in_out, pipefd, argv, envp);
	close_streams(in_out, pipefd);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_out[2];
	int		fd[2];

	if (argc != 5)
	{
		ft_putstr_fd(
			"Usage: ./pipex <input> <command> <command> <output>\n", 2);
		return (EXIT_SUCCESS);
	}
	if (pipe(fd) != 0)
		return (EXIT_FAILURE);
	if (check_access(argv[1], argv[4]) != 0)
	{
		close_streams(NULL, fd);
		return (EXIT_FAILURE);
	}
	in_out[0] = open(argv[1], O_RDONLY);
	in_out[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex(in_out, fd, argv, envp) == EXIT_FAILURE)
	{
		close_streams(in_out, fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
