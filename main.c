/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:49:53 by vkyryche          #+#    #+#             */
/*   Updated: 2026/10/03 20:25:27 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_structures(t_flags *flags, t_bench *bench)
{
	flags->flag = 'a';
	flags->bench = 0;
	flags->f_count = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
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

double run_algorithm(t_stack **a, t_flags flags, t_bench *bench)
{
	t_stack *b;
	double	disorder;
	
	b = NULL;
	disorder = disorder_metric(a);
	if (disorder == 0.0)
		return (0.0);
	if (flags.flag == 'a')
	{
		if (disorder < 0.2)
			min_extraction(a, b, bench);
		else if (disorder < 0.5)
			// medium
		else
			// complex
	}
	else if (flags.flag == 's')
		min_extraction(a, b, bench);
	else if (flags.flag == 'm')
		// medium
	else
		// complex
	return (disorder * 100 + 0.5);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_flags flags;
	t_bench bench;

	stack_a = NULL;
	fill_structures(&flags, &bench);
	if (argc == 1)
		return 0;
	if (parsing(argc, argv, &stack_a, &flags))
	{
		write(2, "Error\n", 6);
		return 1;
	}
	bench.bench = flags.bench;
	bench.disorder = run_algorithm(&stack_a, flags, &bench);
	if (flags.bench)
	{
		bench.strategy = flags.flag;
		display_bench(&bench);
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

~*~*~*~ Bench ~*~*~*~
BENCH TO ERROR
*/
