/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:49:38 by mpascual          #+#    #+#             */
/*   Updated: 2020/10/06 17:52:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  ft_nbrlen doesn't count for the negative sing if the number is < 0
**  It returns ONLY the number of DIGITS
*/

#include "libft.h"

unsigned int	ft_nbrlen(long nb, int base_len)
{
	long	n_digits;

	n_digits = 1;
	if (nb < 0)
		nb *= -1;
	while (nb >= base_len)
	{
		n_digits++;
		nb /= base_len;
	}
	return (n_digits);
}
