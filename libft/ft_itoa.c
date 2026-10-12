/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:15:19 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:50:30 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	number;
	char	*string;
	int		len;

	number = n;
	len = (n < 0) + 1;
	while (number / 10 && ++len)
		number /= 10;
	string = ft_calloc(1, len + 1);
	if (!string)
		return (NULL);
	number = n;
	if (n < 0)
	{
		string[0] = '-';
		number = -number;
	}
	while (len--)
	{
		if (!string[len])
			string[len] = (number % 10) + '0';
		number /= 10;
	}
	return (string);
}
