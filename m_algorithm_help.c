/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_algorithm_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:17:31 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/03 21:53:05 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_sqrt(int n)
{
	int	k;
	
	k = 0;
	while (n >= (k + 1) * (k + 1))
		k = k + 1;
	return (k);
}

static int	chnk_min(t_stack *a, long long int	chunk)
{
	long long int	chunk_min;
	long long int	chunk_size;
	long long int	size;
	long long int	num_chunks;

	size = stack_size(a);
	if (size < 1)
		return (0);
	num_chunks = int_sqrt(size);
	chunk_size = (size + num_chunks - 1)/num_chunks;
	chunk_min = chunk * chunk_size;
	return (chunk_min);
}

static int	chnk_max(t_stack *a, long long int chunk)
{
	long long int	chunk_max;
	long long int	chunk_size;
	long long int	size;
	long long int	num_chunks;

	size = stack_size(a);
	if (size < 1)
		return (0);
	num_chunks = int_sqrt(size);
	chunk_size = (size + num_chunks - 1)/num_chunks;
	chunk_max = chnk_min(a, chunk) + chunk_size - 1;
	return (chunk_max);
}

int	find_in_chunk(t_stack *a, int min, int max)
{
	int		index;

	index = 0;
	while (a != NULL)
	{
		if (a->value >= min && a->value <= max)
			return (index);
		a = a->next;
		index++;			
	}
	return (-1);
}

void	rotate_to_index(t_stack **a, int index)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(*a);
	if (index <= size/2)
	{
		while (i < index)
		{
			ra(a);// dopisat
			i++;
		}
	}
	else
	{
		while (i < size - index)
		{
			rra(a);//dopisat
			i++;
		}
		
	}
}
