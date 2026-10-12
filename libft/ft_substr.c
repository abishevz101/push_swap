/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:38:04 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:48:39 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		subs = malloc(1);
		if (!subs)
			return (NULL);
		*subs = '\0';
		return (subs);
	}
	if (len > s_len - start)
		len = s_len - start;
	subs = malloc(len + 1);
	if (!subs)
		return (NULL);
	ft_memcpy(subs, s + start, len);
	subs[len] = '\0';
	return (subs);
}
