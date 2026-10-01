/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:55:21 by vkyryche          #+#    #+#             */
/*   Updated: 2026/10/01 13:45:31 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(t_stack **head, int value)
{
	t_stack	*mem;
	
	mem = malloc(sizeof(t_stack));
	if (!mem)
		return (1);
	mem -> value = value;
	mem -> next = *head;
	*head = mem;
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

size_t	stack_size(t_stack *head)
{
	size_t	count;

	count = 0;
	while(head != NULL)
	{
		count = count + 1;
		head = head->next;
	}
	return (count);
}

	// count++;
	// count+=1;