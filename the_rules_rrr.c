/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/07 20:56:48 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int rule, t_bench *bench)
{
	t_stack	*prev;
	t_stack	*last;

	if (stack_size(*a) <= 1)
		return ;
	prev = *a;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (rule)
	{
		write(1, "rra\n", 4);
		bench->rra++;
	}
}

void	rrb(t_stack **b, int rule, t_bench *bench)
{
	t_stack	*prev;
	t_stack	*last;

	if (stack_size(*b) <= 1)
		return ;
	prev = *b;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (rule)
	{
		write(1, "rrb\n", 4);
		bench->rrb++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rra(a, 0, bench);
	rrb(b, 0, bench);
	write(1, "rrr\n", 4);
	bench->rrr++;
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*s;

	if (*a == NULL)
		return ;
	s = *a;
	*a = s->next;
	s->next = *b;
	*b = s;
	write(1, "pb\n", 3);
	bench->pb++;
}
