/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:49:53 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/23 21:32:53 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack;
	t_flags flags;

	stack = NULL;
	flags->flag = 'a';
	flags->bench = 0;
	flags->f_count = 0;
	if (argc == 1)
		return 0;
	if (parsing(argc, argv, &stack, &flags))
	{
		print_error();
		return 1;
	}
	return 0;
}

/*
Done: 0. Exit if argc == 1
Partly-done: 1. Add libft to rep and Makefile
2. Validness of arguments
	1) Isn't a number
	2) Isn't an integer
	3) Higher/lower than INT_MAX/INT_MIN
	4) Is duplicate
	!!!Numbers can be separated by space in a same argument!!!
3. Print Error if it occurs and clean the entire stack ("Error\n" to stderr)
4. Write them into stack (from end to beginning)
Partly-done: 5. Acceptence of flags
	- max 1 Flag --simple/--medium/--complex/--adaptive
		more: Error/rewrite
	- max 1 Flag --bench
		more: Error
*/
