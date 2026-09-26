/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:05:08 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/26 19:35:40 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **split_arr)
{
    int i;

	i = 0;
    while (split_arr[i])
        free(split_arr[i++]);
    free(split_arr);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2 || !*s1)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
}

int is_duplicate(t_stack **stack_a, int number)
{
    t_stack *temp;

    temp = *stack_a;
    while (temp)
	{
        if (temp->value == number)
            return (1);
		temp = temp->next;
	}
	if (add_to_stack(number, stack_a))
        return (1);
    return (0);
}

// ft_lstadd_front(t_list **lst, t_list *new)

// free stack
// while (*stack)
// 	{
// 		temp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = temp;
// 	}