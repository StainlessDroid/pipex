/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:37 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/23 14:52:23 by mapascua         ###   ########.fr       */
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

int	clean_exit(int *in_out, int *pipe, char **cmd1, char **cmd2)
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
	ft_free("dd", cmd1, cmd2);
	return (EXIT_FAILURE);
}
