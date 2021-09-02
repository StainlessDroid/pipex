/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:03:35 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/27 18:57:55 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1u;
	unsigned char	*s2u;

	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	i = 0;
	while ((s1u[i] && s2u[i]) && i < n)
	{
		if (s1u[i] != s2u[i])
			return (s1u[i] - s2u[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return (s1u[i] - s2u[i]);
}
