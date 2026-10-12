/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:09:30 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:43:00 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ud;
	const unsigned char	*us;

	ud = (unsigned char *)dest;
	us = (const unsigned char *)src;
	while (n--)
		*ud++ = *us++;
	return (dest);
}
