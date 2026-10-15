/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:11:43 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:43:08 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*udest;
	const unsigned char	*usrc;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	udest = (unsigned char *)dest;
	usrc = (const unsigned char *)src;
	while (n--)
		udest[n] = usrc[n];
	return (dest);
}
