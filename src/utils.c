/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:37 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/19 15:10:35 by mapascua         ###   ########.fr       */
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

int	free_cmds(char **cmd1, char **cmd2)
{
	int	i;

	if (cmd1)
	{
		i = 0;
		while (cmd1[i])
		{
			free(cmd1[i]);
			i++;
		}
		free(cmd1);
	}
	if (cmd2)
	{
		i = 0;
		while (cmd2[i])
		{
			free(cmd2[i]);
			i++;
		}
		free(cmd2);
	}
	return (EXIT_FAILURE);
}
