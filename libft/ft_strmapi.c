/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 14:06:41 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:44:55 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	if (!s || !f)
		return (NULL);
	new_s = malloc(ft_strlen(s) + 1);
	if (!new_s)
		return (NULL);
	i = -1;
	while (s[++i])
		new_s[i] = f(i, s[i]);
	new_s[i] = '\0';
	return (new_s);
}
