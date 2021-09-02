/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:45:01 by mpascual          #+#    #+#             */
/*   Updated: 2020/10/06 17:51:53 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strrev(char *s)
{
	char *s_end;
	char c;

	s_end = s + ft_strlen(s) - 1;
	while (s < s_end)
	{
		c = *s;
		*s++ = *s_end;
		*s_end-- = c;
	}
}

char			*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	n_digits;
	unsigned int	nb;
	unsigned int	i;

	if (nbr < 0)
		nb = (unsigned int)(nbr * -1);
	else
		nb = (unsigned int)nbr;
	n_digits = ft_nbrlen(nbr, 10);
	if (!(str = malloc(n_digits + 1 + (nbr < 0 ? 1 : 0))))
		return (NULL);
	i = 0;
	while (nb >= 10)
	{
		str[i++] = ((nb % 10) + 48);
		nb /= 10;
		n_digits--;
	}
	str[i++] = (nb % 10 + 48);
	if (nbr < 0 && (str[i] = '-'))
		i++;
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
