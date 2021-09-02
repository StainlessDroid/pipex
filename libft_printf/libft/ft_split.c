/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:47:25 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/27 15:50:17 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_str(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static int		numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**resp(char const *s, char **dst, char c, int l)
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	while (s[i] != '\0' && y < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(dst[y] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1)))
			return (0);
		while (s[i] != '\0' && s[i] != c)
			dst[y][k++] = s[i++];
		dst[y][k] = '\0';
		y++;
	}
	dst[y] = 0;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	int		n;

	if (s == 0)
		return (0);
	n = count_str(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (n + 1))))
		return (0);
	return (resp(s, dst, c, n));
}
