/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:07:26 by zabishev          #+#    #+#             */
/*   Updated: 2026/09/26 19:19:52 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	add_to_stack(t_stack **head, int value)
// {
// 	t_stack	*mem;
	
// 	mem = malloc(sizeof(t_stack));
// 	if (!mem)
// 		return ;
// 	mem -> value = value;//значит пое value внутри структуры, на которую указывает mem. То есть мы обращаемся к конкретной ячейке памяти внутри созданного узла. К той ее части, где хранится число.
// 	mem -> next = *head;
// 	*head = mem;
// }


void	add_to_stack_end(t_stack **head, int value)
{
	size_t	count;

	count = 0;
	while(*head != NULL)
	{
		count = count + 1;
	}
}