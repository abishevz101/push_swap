/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:26:24 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:50:20 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	while (s1[left] && ft_strchr(set, s1[left]))
		left++;
	right = ft_strlen(s1);
	while (right > left && ft_strchr(set, s1[right - 1]))
		right--;
	return (ft_substr(s1, left, right - left));
}
