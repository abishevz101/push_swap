/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_algorithmc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:16:14 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/01 17:20:54 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	count_smaller(t_stack *a, int target)
{
	long int	count;
	t_stack		*current;//промежуточный указатель, гуляющий по списку

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
	t_stack	*current;
	int		range;

	current = a;
	while (current != NULL)
	{
		range = count_smaller(a, current->value);
		current->value = range;
		current = current->next;
	}
}
