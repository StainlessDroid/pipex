/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:19:51 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/19 15:44:42 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int			ft_len(const char *str)
{
	unsigned int l;

	l = 0;
	while (*str >= '0' && *str <= '9')
	{
		l++;
		str++;
	}
	l--;
	return (l);
}

static unsigned long int	ft_expo(int n)
{
	int i;
	int x;

	x = 1;
	i = n;
	while (i > 0)
	{
		x *= 10;
		i--;
	}
	return (x);
}

int							ft_atoi(const char *str)
{
	unsigned int	len;
	unsigned long	nbr;
	unsigned int	neg;

	nbr = 0;
	neg = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	len = ft_len(str);
	while (*str >= '0' && *str <= '9')
	{
		nbr += (*str - '0') * ft_expo(len);
		len--;
		str++;
	}
	if (neg == 1)
		return (nbr * -1);
	else
		return (nbr);
}
