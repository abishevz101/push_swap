/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:52:40 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/12 14:15:23 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **a, t_bench *bench)
{
	t_stack	*current;
	int		size;
	int		i;
	int		swapped;

	current = *a;
	size = stack_size(*a);
	swapped = 1;
	while (swapped == 1)
	{
		i = 0;
		swapped = 0;
		while (i < size -1)
		{
			current = *a;
			if (current->value > current->next->value)
			{
				sa(a, 1, bench);
				swapped = 1;
			}
			ra(a, 1, bench);
			i++;
		}
		ra(a, 1, bench);
	}
}

int	find_insert_index(t_stack *a, int value)
{
	t_stack	*current;
	int		index;
	int		best;
	int		best_index;

	current = a;
	index = 0;
	best = INT_MAX;
	best_index = 0;
	while (current != NULL)
	{
		if (current->value > value && current->value < best)
		{
			best_index = index;
			best = current->value;
		}
		current = current->next;
		index++;
	}
	return (best_index);
}

static void	push_chunk(t_stack **a, t_stack **b, t_bench *bench, int range[2])
{
	int	index;

	index = find_in_chunk(*a, range[0], range[1]);
	while (index != -1)
	{
		rotate_to_index(a, index, bench);
		pb(a, b, bench);
		index = find_in_chunk(*a, range[0], range[1]);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	chunk;
	int	range[2];

	bench->complexity = "O(n√n)";
	size = stack_size(*a);
	if (size < 1)
		return ;
	range_numbers(*a);
	chunk = -1;
	while (++chunk < int_sqrt(size) - 1)
	{
		range[0] = chnk_min(size, chunk);
		range[1] = chnk_max(size, chunk);
		push_chunk(a, b, bench, range);
	}
	bubble_sort(a, bench);
	while (*b != NULL)
	{
		rotate_to_index(a, find_insert_index(*a, (*b)->value), bench);
		pa(a, b, bench);
	}
	rotate_min_to_top(a, bench);
}
