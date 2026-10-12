/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:20:13 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:43:31 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	long	decimal;

	num = n;
	decimal = 1;
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	while (num / decimal >= 10)
		decimal *= 10;
	while (decimal)
	{
		ft_putchar_fd(num / decimal + '0', fd);
		num %= decimal;
		decimal /= 10;
	}
}
