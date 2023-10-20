/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:58 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:51 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	pa(t_list **a, t_list **b)
{
	t_list	*top_b;

	if (!*b)
		return (-1);
	top_b = *b;
	*b = (*b)->next;
	ft_list_add_front(a, top_b);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	t_list	*top_a;

	if (!*a)
		return (-1);
	top_a = *a;
	*a = (*a)->next;
	ft_list_add_front(b, top_a);
	ft_putendl_fd("pb", 1);
	return (0);
}
