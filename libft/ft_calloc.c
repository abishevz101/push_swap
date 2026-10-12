/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:28:36 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:40:31 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*s;
	size_t		mult;

	mult = nmemb * size;
	if (size && mult / size != nmemb)
		return (NULL);
	s = malloc(mult);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, mult);
	return (s);
}
