/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:37 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/26 16:58:50 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char *infile, char *outfile)
{
	if (access(infile, R_OK) != 0)
	{
		perror("input file");
		return (EXIT_FAILURE);
	}
	if (access(outfile, F_OK) == 0)
	{
		if (access(outfile, W_OK) != 0)
		{
			perror("output file");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	try_paths(char **cmd, char **envp)
{
	char	**paths;
	char	*tmp;
	int		i;

	paths = ft_split(get_path(envp), ':');
	if (paths == NULL)
		return ;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin_chain(3, paths[i], "/", cmd[0]);
		if (access(tmp, X_OK) == 0)
			execve(tmp, cmd, envp);
		ft_free("ss", paths[i], tmp);
		i++;
	}
	free(paths);
	if (access(cmd[0], X_OK) == 0)
		execve(cmd[0], cmd, envp);
	perror("execve");
}

char	*get_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 6))
			return (envp[i] + 5);
		else
			i++;
	}
	return (path);
}

void	close_streams(int *in_out, int *pipe)
{
	if (in_out)
	{
		close(in_out[0]);
		close(in_out[1]);
	}
	if (pipe)
	{
		close(pipe[0]);
		close(pipe[1]);
	}
}
