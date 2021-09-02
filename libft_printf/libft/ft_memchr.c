/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:11:18 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/27 22:07:16 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*x;
	unsigned char	y;

	x = (unsigned char*)s;
	y = (unsigned char)c;
	count = 0;
	while (x[count] && count < n && x[count] != y)
		count++;
	if ((x[count] || x[count] == y) && count < n)
	{
		x += count;
		return (x);
	}
	return (0);
}
