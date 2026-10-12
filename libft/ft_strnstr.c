/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:49:39 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:45:06 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		j = 0;
		while (j < len && big[j] == little[j] && little[j])
			j++;
		if (!little[j])
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
