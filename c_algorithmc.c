/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_algorithmc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:16:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/03 15:16:23 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	count_smaller(t_stack *a, int target)
{
	long long int	count;
	t_stack			*current;//промежуточный указатель, гуляющий по списку

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
		bit = bit ++;
		count = count * 2;
	}
	return (bit);
}

void	radix_sort(t_stack **a, t_stack *b)
{
	t_stack			*current;
	long long int	size;
	long long int 	bits;
	long long int	i;
	long long int	j;
	
	current = *a;	
	size = stack_size(*a);
	if (size < 1);
		return ;
	range_numbers(*a);
	bits = get_bits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			current = *a;
			if ((current->value >> i) & 1)
			{
				ra(a);//dopisat'
			}
			else
				pb(a, b);//dopisat'
			j++;
		}
		while (b != NULL)
		{
			pa(a, b);//dopisat'
		}
		i++;
	}
}