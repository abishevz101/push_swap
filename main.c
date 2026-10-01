/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:49:53 by vkyryche          #+#    #+#             */
/*   Updated: 2026/10/01 17:22:28 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_flags(t_flags *flags)
{
	flags->flag = 'a';
	flags->bench = 0;
	flags->f_count = 0;
	flags->op_count = 0;
}

double disorder_metric(t_stack **stack_a)
{
	t_stack *current;
    t_stack *temp;
    int     mistakes;
    int     total_pairs;

    mistakes = 0;
    total_pairs = 0;
    current = *stack_a;
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

void run_algorithm(t_stack **a, t_flags flags)
{
	t_stack *b;
	double	disorder;
	
	b = NULL;
	disorder = disorder_metric(a);
	if (disorder == 0.0)
		return ;
	if (flags.flag == 'a')
	{
		if (disorder < 0.2)
			min_extraction(a, &b, &flags);
		else if (disorder < 0.5)
			// medium
		else
			// complex
	}
	else if (flags.flag == 's')
		min_extraction(a, &b, &flags);
	else if (flags.flag == 'm')
		// medium
	else
		// complex
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_flags flags;
	char	*operations;

	stack_a = NULL;
	fill_flags(flags);
	if (argc == 1)
		return 0;
	if (parsing(argc, argv, &stack_a, &flags))
	{
		write(2, "Error\n", 6);
		return 1;
	}
	run_algorithm(&stack_a, flags);
	if (flags.bench)
	{
		operations = ft_itoa(flags.op_count);
		write(1, "Total operations: ", 18);
		write(1, operations, ft_strlen(operations));
		free(operations);
	}
	free_stack(&stack_a);
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
