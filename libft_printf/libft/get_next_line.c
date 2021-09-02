/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:55:42 by mpascual          #+#    #+#             */
/*   Updated: 2020/11/17 20:38:34 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdel(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int				ft_putline(int fd, char **s, char **line)
{
	int		size;
	char	*tmp;

	size = 0;
	while (s[fd][size] != '\n')
		size++;
	*line = ft_substr(s[fd], 0, size);
	tmp = ft_strdup(&s[fd][size + 1]);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int				output(int ret, int fd, char **s, char **line)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		ft_strdel(&s[fd]);
		return (0);
	}
	else if (ft_strchr(s[fd], '\n'))
		return (ft_putline(fd, s, line));
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static char		*s[4096];
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(ret, fd, s, line));
}
