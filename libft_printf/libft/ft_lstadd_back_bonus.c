/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:29:45 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/27 19:28:43 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *n)
{
	t_list	*tmp;

	if (alst != NULL)
	{
		tmp = *alst;
		if (*alst == NULL)
			*alst = n;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = n;
		}
	}
}
