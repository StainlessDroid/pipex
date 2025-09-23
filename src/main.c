/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:23:14 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/23 17:37:04 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd1(int *fd, int input, char **cmd1, char **envp)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = 0;
	if (!cmd1)
		return (EXIT_FAILURE);
	paths = ft_split(get_path(envp), ':');
	dup2(fd[1], 1);
	dup2(input, 0);
	close(fd[1]);
	while (paths[i])
	{
		tmp = ft_strjoin_chain(3, paths[i], "/", cmd1[0]);
		execve(tmp, cmd1, envp);
		ft_free("ss", paths[i], tmp);
		i++;
	}
	execve(cmd1[0], cmd1, envp);
	free(paths);
	perror("command not found");
	return (EXIT_FAILURE);
}

int	exec_cmd2(int *fd, int output, char **cmd2, char **envp)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = 0;
	if (!cmd2)
		return (EXIT_FAILURE);
	paths = ft_split(get_path(envp), ':');
	dup2(fd[0], 0);
	dup2(output, 1);
	close(fd[0]);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin_chain(3, paths[i], "/", cmd2[0]);
		execve(tmp, cmd2, envp);
		ft_free("ss", paths[i], tmp);
		i++;
	}
	execve(cmd2[0], cmd2, envp);
	free(paths);
	perror("command not found");
	return (EXIT_FAILURE);
}

void	pipex(int *in_out, char **cmd1, char **cmd2, char **envp)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;

	if (pipe(fd) != 0)
	{
		perror("Error: pipe() failed\n");
		exit(clean_exit(in_out, NULL, cmd1, cmd2));
	}
	child1 = fork();
	if (child1 < 0)
	{
		perror("Error: fork() failed\n");
		exit(clean_exit(in_out, fd, cmd1, cmd2));
	}
	if (child1 == 0)
	{
		if (exec_cmd1(fd, in_out[0], cmd1, envp) == EXIT_FAILURE)
			exit(clean_exit(in_out, fd, cmd1, cmd2));
	}
	child2 = fork();
	if (child2 < 0)
	{
		perror("Error: fork() failed\n");
		exit(clean_exit(in_out, fd, cmd1, cmd2));
	}
	if (child2 == 0)
	{
		if (exec_cmd2(fd, in_out[1], cmd2, envp) == EXIT_FAILURE)
			exit(clean_exit(in_out, fd, cmd1, cmd2));
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_out[2];
	char	**cmd_arg1;
	char	**cmd_arg2;

	if (argc != 5)
	{
		perror("Wrong number of arguments");
		return (EXIT_FAILURE);
	}
	cmd_arg1 = ft_split(argv[2], ' ');
	cmd_arg2 = ft_split(argv[3], ' ');
	if (!cmd_arg1[0] || !cmd_arg2[0] || check_access(argv[1], argv[4]) != 0)
		return (ft_free("dd", cmd_arg1, cmd_arg2), EXIT_FAILURE);
	else
	{
		in_out[0] = open(argv[1], O_RDONLY);
		in_out[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	pipex(in_out, cmd_arg1, cmd_arg2, envp);
	clean_exit(in_out, NULL, cmd_arg1, cmd_arg2);
	return (EXIT_SUCCESS);
}
