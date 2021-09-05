/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 02:18:02 by mpascual          #+#    #+#             */
/*   Updated: 2021/09/05 02:20:02 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     check_access(char *infile, char *outfile)
{
    if (access(infile, R_OK) != 0)
    {
        perror("input.txt : ");
        return (EXIT_FAILURE);
    }
    if (access(outfile, F_OK) == 0)
    {
        if (access(outfile, W_OK) != 0)
        {
        perror("output.txt ");
        return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

char    *get_path(char **envp)
{
    char    *path;
    int     i;

    i = 0;
    path = NULL;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", 6))
            return(envp[i] + 5);
        else
            i++;
    }
    return(path);
}