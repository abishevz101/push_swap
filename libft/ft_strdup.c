/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:29:01 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:46:23 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s) + 1;
	new_str = malloc(len);
	if (!new_str)
		return (NULL);
	return (ft_memcpy(new_str, s, len));
}
