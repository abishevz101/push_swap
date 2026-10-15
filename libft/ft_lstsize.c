/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:58:58 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:50:57 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst && ++size)
		lst = lst->next;
	return (size);
}
