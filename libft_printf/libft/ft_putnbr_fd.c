/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:48:18 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/25 18:50:49 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	int		a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = a * -1;
	}
	if (a >= 10)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putchar_fd((a % 10) + '0', fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
}
