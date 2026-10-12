/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:16:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/12 13:57:23 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_smaller(t_stack *a, int target)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = a;
	while (current != NULL)
	{
		if (current->value < target)
			count++;
		current = current->next;
	}
	return (count);
}

static int	*collect_ranks(t_stack *a, int size)
{
	int		*ranks;
	t_stack	*current;
	int		i;

	ranks = malloc(sizeof(int) * size);
	if (!ranks)
		return (NULL);
	current = a;
	i = 0;
	while (current != NULL)
	{
		ranks[i] = count_smaller(a, current->value);
		current = current->next;
		i++;
	}
	return (ranks);
}

void	range_numbers(t_stack *a)
{
	t_stack	*current;
	int		i;
	int		*ranks;

	ranks = collect_ranks(a, stack_size(a));
	if (!ranks)
		return ;
	current = a;
	i = 0;
	while (current != NULL)
	{
		current->value = ranks[i];
		current = current->next;
		i++;
	}
	free (ranks);
}

int	get_bits(int size)
{
	int	bit;
	int	count;

	bit = 0;
	count = 1;
	while (count < size)
	{
		bit++;
		count = count * 2;
	}
	return (bit);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	bench->complexity = "O(nlogn)";
	size = stack_size(*a);
	if (size < 1)
		return ;
	range_numbers(*a);
	bits = get_bits(size);
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((*a)->value >> i) & 1)
				ra(a, 1, bench);
			else
				pb(a, b, bench);
		}
		while (*b != NULL)
			pa(a, b, bench);
	}
}
