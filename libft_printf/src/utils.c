/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:03:06 by mpascual          #+#    #+#             */
/*   Updated: 2020/11/17 20:57:58 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		init_flags(t_var *var)
{
	var->precision = 0;
	var->width = 0;
	var->format_pos = 0;
	var->minus = FALSE;
	var->zero = FALSE;
	var->is_precision = FALSE;
	var->nb_neg = FALSE;
}

int			star(t_var *var, va_list arg)
{
	int	i;

	i = 1;
	var->width = va_arg(arg, int);
	if (var->width < 0)
	{
		minus(var);
		var->width *= -1;
	}
	return (i);
}

int			is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

int			get_number(const char *str)
{
	int			i;
	int			len;
	char		*number;
	int			tmp;

	i = 0;
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	if (!(number = malloc(len + 1)))
		return (-1);
	i = 0;
	while (len > 0)
	{
		number[i] = str[i];
		i++;
		len--;
	}
	number[i] = '\0';
	tmp = ft_atoi(number);
	free(number);
	return (tmp);
}

void		ft_itohex(unsigned long nb, t_bool mayus, t_var *var)
{
	unsigned long	num;
	int				a;

	a = mayus ? 55 : 87;
	num = nb;
	if (num >= 16)
	{
		ft_itohex(num / 16, mayus, var);
		ft_putchar(num % 16 + (num % 16 > 9 ? a : '0'));
		var->printed_chars++;
	}
	else
		var->printed_chars += ft_putchar(num + (num % 16 > 9 ? a : '0'));
}
