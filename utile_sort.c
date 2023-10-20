/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:52:26 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/18 18:29:24 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	return (0);
}

int	get_min1(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->lindex;
	while (head->next)
	{
		head = head->next;
		if ((head->lindex < min) && head->lindex != val)
			min = head->lindex;
	}
	return (min);
}

int	get_dist(t_list **stack, int index)
{
	t_list	*head;
	int		dist;

	dist = 0;
	head = *stack;
	while (head)
	{
		if (head->lindex == index)
			break ;
		dist++;
		head = head->next;
	}
	return (dist);
}
