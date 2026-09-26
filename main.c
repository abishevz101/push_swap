/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:49:53 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/26 19:59:07 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error()
{
	write(2, "Error\n", 6);
}

double disorder_metric(t_stack **stack_a)
{
	t_stack *current;
    t_stack *temp;
    int     mistakes;
    int     total_pairs;

    mistakes = 0;
    total_pairs = 0;
    current = stack;
    while (current)
    {
        temp = current->next;
        while (temp)
        {
            total_pairs++;
            if (current->value > temp->value)
                mistakes++;
            temp = temp->next;
        }
        current = current->next;
    }
	if (total_pairs == 0)
        return (0.0);
	return ((double)mistakes / total_pairs);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_flags flags;

	stack_a = NULL;
	flags.flag = 'a';
	flags.bench = 0;
	flags.f_count = 0;
	if (argc == 1)
		return 0;
	if (parsing(argc, argv, &stack_a, &flags))
	{
		print_error();
		return 1;
	}
	disorder_metric(&stack_a);
	return 0;
}

/*
~*~*~*~ Parsing ~*~*~*~
Done: 0. Exit if argc == 1
Partly-done: 1. Add libft to rep and Makefile
Done: 2. Validness of arguments
	1) Isn't a number
	2) Isn't an integer
	3) Higher/lower than INT_MAX/INT_MIN
	4) Is duplicate
	!!!Numbers can be separated by space in a same argument!!!
Done: 3. Print Error if it occurs and clean the entire stack ("Error\n" to stderr)
Done: 4. Write them into stack (from end to beginning)
Partly-done: 5. Acceptence of flags
	- max 1 Flag --simple/--medium/--complex/--adaptive
		more: Error/rewrite
	- max 1 Flag --bench
		more: Error

~*~*~*~ Parcing ~*~*~*~
*/
