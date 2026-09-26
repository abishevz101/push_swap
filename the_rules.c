/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/09/26 15:00:21 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
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
}

void	sb(t_stack **b)
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
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
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
}

void ra(t_stack **a)
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
}

void rb(t_stack **b)
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
}
void rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
void	rra(t_stack **a)
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
}
void	rrb(t_stack **b)
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
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
