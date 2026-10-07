/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:16:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/07 12:30:47 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	count_smaller(t_stack *a, int target)
{
	long long int	count;
	t_stack			*current;

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

void	range_numbers(t_stack *a)
{
	t_stack				*current;
	long long int		range;

	current = a;
	while (current != NULL)
	{
		range = count_smaller(a, current->value);
		current->value = range;
		current = current->next;
	}
}

int	get_bits(int size)
{
	long long int	bit;
	long long int	count;

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
	long long int	size;
	long long int 	bits;
	long long int	i;
	long long int	j;
	
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
