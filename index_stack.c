/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:43:40 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:13 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft/libft.h"
#include "inc/push_swap.h"

t_list	*search_index_min(t_list **stack)
{
	t_list	*head;
	t_list	*min_cell;
	int		min_so_far;

	min_cell = NULL;
	min_so_far = INT_MAX;
	head = *stack;
	while (head)
	{
		if ((head->lindex == -1) && (head->value <= min_so_far))
		{
			min_cell = head;
			min_so_far = head->value;
		}
		head = head->next;
	}
	return (min_cell);
}

void	get_index(t_list **stack)
{
	t_list	*head;
	int		i;

	i = 0;
	head = search_index_min(stack);
	while (head)
	{
		head->lindex = i++;
		head = search_index_min(stack);
	}
}
