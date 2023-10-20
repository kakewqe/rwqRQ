/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:44 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/16 13:30:54 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	do_rra_or_rrb(t_list **stack)
{
	t_list	*prev_last;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev_last = NULL;
	last = *stack;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	if (prev_last)
		prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

int	rra(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return (-1);
	do_rra_or_rrb(stack);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return (-1);
	do_rra_or_rrb(stack);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
	return (0);
}
