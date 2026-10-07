/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/07 20:56:16 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int rule, t_bench *bench)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*a) <= 1)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	last->next = first;
	first->next = NULL;
	if (rule)
	{
		write(1, "ra\n", 3);
		bench->ra++;
	}
}

void	rb(t_stack **b, int rule, t_bench *bench)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*b) <= 1)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	last->next = first;
	first->next = NULL;
	if (rule)
	{
		write(1, "rb\n", 3);
		bench->rb++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a, 0, bench);
	rb(b, 0, bench);
	write(1, "rr\n", 3);
	bench->rr++;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*s;

	if (*b == NULL)
		return ;
	s = *b;
	*b = s->next;
	s->next = *a;
	*a = s;
	write(1, "pa\n", 3);
	bench->pa++;
}
