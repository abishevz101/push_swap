/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:59:51 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:46:52 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = malloc(len1 + len2 + 1);
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s1, len1);
	ft_memcpy(new_s + len1, s2, len2 + 1);
	return (new_s);
}
