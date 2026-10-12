/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:36:18 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:50:47 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*structure;

	structure = malloc(sizeof(t_list));
	if (!structure)
		return (NULL);
	structure->content = content;
	structure->next = NULL;
	return (structure);
}
