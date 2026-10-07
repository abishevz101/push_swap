/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:22:33 by vkyryche          #+#    #+#             */
/*   Updated: 2026/10/07 13:03:16 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_each_op(t_bench *bench)
{
	write(2, "sa: ", 4);
	ft_putnbr_fd(bench->sa, 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(bench->sb, 2);
	write(2, " ss: ", 5);
	ft_putnbr_fd(bench->ss, 2);
	write(2, " pa: ", 5);
	ft_putnbr_fd(bench->pa, 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);

	write(2, "ra: ", 4);
	ft_putnbr_fd(bench->ra, 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(bench->rb, 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(bench->rr, 2);
	write(2, " rra: ", 6);
	ft_putnbr_fd(bench->rra, 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(bench->rrb, 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}

void display_strategy(t_bench *bench)
{
	write(2, "Strategy: ", 10);
	if (bench->strategy == 'a')
		write(2, "Adaptive / ", 11);
	else if (bench->strategy == 's')
		write(2, "Simple / ", 9);
	else if (bench->strategy == 'm')
		write(2, "Medium / ", 9);
	else
		write(2, "Complex / ", 10);
	ft_putstr_fd(bench->complexity, 2);
	write(2, "\n", 1);
}

void display_bench(t_bench *bench)
{
	int operations;
	int fraction_part;

	operations = bench->sa + bench->sb + bench->ss + bench->pa
		+ bench->pb + bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
	write(2,"Disorder: ", 10);
	bench->disorder += 0.005;
	ft_putnbr_fd((int)(bench->disorder), 2);
	write(2, ".", 1);
	bench->disorder -= (int)(bench->disorder);
	bench->disorder *= 100;
	fraction_part = (int)(bench->disorder);
	if (fraction_part < 10)
    	write(2, "0", 1);
	ft_putnbr_fd(fraction_part, 2);
	write(2, "%\n", 2);
	display_strategy(bench);
	write(2, "Total operations: ", 18);
	ft_putnbr_fd(operations, 2);
	write(2, "\n", 1);
	display_each_op(bench);
}
