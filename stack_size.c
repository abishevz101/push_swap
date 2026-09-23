/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:42:31 by zabishev          #+#    #+#             */
/*   Updated: 2026/09/23 16:30:22 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *head)
{
	size_t	count;

	count = 0;
	while(head != NULL)
	{
		count = count +1;
		head = head -> next;
	}
	return (count);
}
