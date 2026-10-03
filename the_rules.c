/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/03 16:38:54 by vkyryche         ###   ########.fr       */
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
		if (!bench->bench)
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
		if (!bench->bench)
			write(1, "sb\n", 3);
		bench->sb++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa(a, 0, bench);
	sb(b, 0, bench);
	if (!bench->bench)
		write(1, "ss\n", 3);
	bench->ss++;
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
	if (!bench->bench)
		write(1, "pa\n", 3);
	bench->pa++;
}

void pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack *s;

	if (*a == NULL)
		return ;
	s = *a;
	*a = s->next;
	s->next = *b;
	*b = s;
	if (!bench->bench)
			write(1, "pb\n", 3);
	bench->pb++;
}

void ra(t_stack **a, int rule, t_bench *bench)
{
	t_stack *first;
	t_stack *last;

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
		if (!bench->bench)
			write(1, "ra\n", 3);
		bench->ra++;
	}
}

void rb(t_stack **b, int rule, t_bench *bench)
{
	t_stack *first;
	t_stack *last;

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
		if (!bench->bench)
			write(1, "rb\n", 3);
		bench->rb++;
	}
}
void rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a, 0, bench);
	rb(b, 0, bench);
	if (!bench->bench)
		write(1, "rr\n", 3);
	bench->rr++;
}
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
		if (!bench->bench)
			write(1, "rra\n", 3);
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
		if (!bench->bench)
			write(1, "rrb\n", 3);
		bench->rrb++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rra(a, 0, bench);
	rrb(b, 0, bench);
	if (!bench->bench)
		write(1, "rrr\n", 4);
	bench->rrr++;
}
