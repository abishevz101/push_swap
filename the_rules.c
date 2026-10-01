/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/01 14:14:27 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int rule)
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
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int rule)
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
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*s;

	if (*b == NULL)
		return ;
	s = *b;
	*b = s->next;
	s->next = *a;
	*a = s;
	write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
	t_stack *s;

	if (*a == NULL)
		return ;
	s = *a;
	*a = s->next;
	s->next = *b;
	*b = s;
	write(1, "pb\n", 3);
}

void ra(t_stack **a, int rule)
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
		write(1, "ra\n", 3);
}

void rb(t_stack **b, int rule)
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
		write(1, "rb\n", 3);
}
void rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
void	rra(t_stack **a, int rule)
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
		write(1, "rra\n", 4);
}
void	rrb(t_stack **b, int rule)
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
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
