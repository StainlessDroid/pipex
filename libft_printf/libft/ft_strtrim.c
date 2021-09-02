/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:02:21 by mpascual          #+#    #+#             */
/*   Updated: 2019/11/27 19:13:19 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;
	size_t	start;
	size_t	end;
	char	*nstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, (int)s1[start]) && start < end)
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strchr(set, (int)s1[end]) && end > 0)
		end--;
	len = 1 + end - start;
	if (!(nstr = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len)
		nstr[i++] = s1[start++];
	nstr[i] = '\0';
	return (nstr);
}
