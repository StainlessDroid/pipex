/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:13:50 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/23 16:29:52 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int	i;
	unsigned int	l;
	char			*ptr;

	i = 0;
	l = ft_strlen(src);
	if (!(ptr = malloc(l + 1)))
		return (NULL);
	else
	{
		while (src[i] != 0)
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
}
