/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:17:27 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/07 20:46:05 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *a)
{
	t_stack	*current;
	int		min;
	int		min_index;
	int		i;

	min_index = 0;
	i = 0;
	min = a->value;
	current = a;
	while (current != NULL)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	rotate_min_to_top(t_stack **a, t_bench *bench)
{
	int	index;
	int	size;
	int	i;

	i = 0;
	index = find_min_index(*a);
	size = stack_size(*a);
	if (index <= size / 2)
	{
		while (i < index)
		{
			ra(a, 1, bench);
			i++;
		}
	}
	else
	{
		while (i < size - index)
		{
			rra(a, 1, bench);
			i++;
		}
	}
}

void	min_extraction(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->complexity = "O(n^2)";
	while (stack_size(*a) > 1)
	{
		rotate_min_to_top(a, bench);
		pb(a, b, bench);
	}
	while (*b != NULL)
	{
		pa(a, b, bench);
	}
}
