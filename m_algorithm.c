/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:52:40 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/04 20:56:40 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	long long int	size;
	long long int	num_chunks;
	long long int	chunk;
	int	min;
	int	max;
	int	index;

	size = stack_size(*a);
	if (size < 1)
		return ;
	range_numbers(*a);
	num_chunks = int_sqrt(size);
	chunk = 0;

	while (chunk < num_chunks - 1)
	{
		min = chnk_min(*a, chunk);
		max = chnk_max(*a, chunk);
		index = find_in_chunk(*a, min, max);
		while (index != -1)//пока в этом чанке остались элементы
		{
			rotate_to_index(a, index);
			pb(a, b, bench);
			index = find_in_chunk(*a, min, max);
		}
		chunk++;
	}
	bubble_sort(a);
	while (*b != NULL)
	{
		index = find_insert_index(*a, (*b)->value);
		rotate_to_index(a, index);
		pa(a, b);
	}
	rotate_min_to_top(a);
}

void	bubble_sort(t_stack **a)
{
	t_stack			*current;
	long long int	size;
	long long int	i;
	long long int	swapped;
	
	current = *a;
	size = stack_size(*a);
	swapped = 1;
	while(swapped == 1)
	{
		i = 0;//sbrasyvajem pered kazhdym prohodom
		swapped = 0;
		while (i < size -1)
		{
			current = *a;//berem aktualnuju golovu na kazhdom shage
			if (current->value > current->next->value)
			{
				sa(a);
				swapped = 1;
			}
			ra(a);
			i++;
		}
		ra(a);
	}
}

int	find_insert_index(t_stack *a, int value)
{
	t_stack			*current;
	long long int	index;
	long long int	best;
	long long int	best_index;
	
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
