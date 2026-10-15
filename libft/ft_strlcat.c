/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:22:30 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:51:17 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + ft_strlen(src));
	return (dst_len + ft_strlcpy(dst + dst_len, src, size - dst_len));
}
