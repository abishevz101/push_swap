/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/07 20:51:10 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int rule, t_bench *bench)
{
	t_stack	*b;
	t_stack	*c;

	if (stack_size(*a) <= 1)
		return ;
	b = *a;
	c = (*a)->next->next;
	*a = (*a)->next;
	(*a)->next = b;
	b->next = c;
	if (rule)
	{
		write(1, "sa\n", 3);
		bench->sa++;
	}
}

void	sb(t_stack **b, int rule, t_bench *bench)
{
	t_stack	*a;
	t_stack	*c;

	if (stack_size(*b) <= 1)
		return ;
	a = *b;
	c = (*b)->next->next;
	*b = (*b)->next;
	(*b)->next = a;
	a->next = c;
	if (rule)
	{
		write(1, "sb\n", 3);
		bench->sb++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa(a, 0, bench);
	sb(b, 0, bench);
	write(1, "ss\n", 3);
	bench->ss++;
}
