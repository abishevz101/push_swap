/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:42:35 by zabishev          #+#    #+#             */
/*   Updated: 2026/10/12 17:18:53 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_bench *bench)
{
	t_stack	*current;
	int		af;
	int		b;
	int		c;

	current = *a;
	af = current->value;
	b = current->next->value;
	c = current->next->next->value;
	if (af > b && b < c && af > c)
		ra(a, 1, bench);
	if (af < b && b > c && af > c)
		rra(a, 1, bench);
	if (af > b && b < c && af < c)
		sa(a, 1, bench);
	if (af > b && b > c && af > c)
	{
		sa(a, 1, bench);
		rra(a, 1, bench);
	}
	else if (af < b && b > c && af < c)
	{
		sa(a, 1, bench);
		ra(a, 1, bench);
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

void	choose_path(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->complexity = "O(n^2)";
	if (stack_size(*a) == 2)
		sa(a, 1, bench);
	else if (stack_size(*a) == 3)
		sort_three(a, bench);
	else if (stack_size(*a) == 4)
	{
		rotate_min_to_top(a, bench);
		pb(a, b, bench);
		sort_three(a, bench);
		pa(a, b, bench);
	}
	else if (stack_size(*a) == 5)
		sort_five(a, b, bench);
	else
		min_extraction(a, b, bench);
}
