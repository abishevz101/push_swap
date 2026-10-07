/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:42:35 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/07 18:57:29 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, int	rule, t_bench *bench)
{
	t_stack	*current;
	int	af;
	int	b;
	int	c;

	current = *a;
	af = current->value;
	b = current->next->value;
	c = current->next->next->value;
	
	// if (stack_size(a) == 2)
	// 	sa(a, rule, bench);
	// else if (stack_size(a) == 3)
	// 	sort_three(a, rule, bench);
	// else
	// 	sort_five(a, rule, bench);
	
	if (af > b && b < c && af > c)//312
		ra(a, rule, bench);
	if (af < b && b > c && af > c)//231
		rra(a, rule, bench);
	if (af > b && b < c && af < c)//213
		sa(a, rule, bench);
	if (af > b && b > c && af > c)//321
		{
			sa(a, rule, bench);
			rra(a, rule, bench);
		}
	else if (af < b && b > c && af < c)//132
		{
			sa(a, rule, bench);
			ra(a, rule, bench);
		}
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	long long int	i;

	i = 0;
	while (i < 2)
	{
		rotate_min_to_top(a, bench);
		pb(a, b, bench);
		i++;
	}
	sort_three(a, bench);
	pa(a, b, bench);
	pa(a, b, bench);
}