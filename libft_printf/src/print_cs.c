/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:23:22 by mpascual          #+#    #+#             */
/*   Updated: 2020/11/13 12:16:57 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		print_c(char c, t_var *var)
{
	int		n_printed;

	n_printed = 0;
	if (var->minus)
		n_printed += ft_putchar(c);
	while (var->width > 1)
	{
		if (var->zero)
			n_printed += ft_putchar('0');
		else
			n_printed += ft_putchar(' ');
		var->width--;
	}
	if (var->minus == FALSE)
		n_printed += ft_putchar(c);
	return (n_printed);
}

int		print_s(char *str, t_var *var)
{
	int		n_printed;
	int		len;

	if (!str)
		str = "(null)";
	n_printed = 0;
	len = (var->is_precision && !var->precision) ? 0 : ft_strlen(str);
	if (var->is_precision && var->precision <= len)
		len = var->precision;
	if (var->minus)
		n_printed += write(1, str, len);
	while (var->width > len)
	{
		if (var->zero)
			n_printed += ft_putchar('0');
		else
			n_printed += ft_putchar(' ');
		var->width--;
	}
	if (var->minus == FALSE)
		n_printed += write(1, str, len);
	return (n_printed);
}
