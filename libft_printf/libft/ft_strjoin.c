/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:17:27 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/23 20:06:17 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*nstr;
	unsigned int	i1;
	unsigned int	i2;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	else if (!(nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	else
	{
		while (s1[i1] != 0)
		{
			nstr[i1] = s1[i1];
			i1++;
		}
		while (s2[i2] != 0)
		{
			nstr[i1 + i2] = s2[i2];
			i2++;
		}
		nstr[i1 + i2] = '\0';
		return (nstr);
	}
}
