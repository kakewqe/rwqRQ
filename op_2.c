/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:34 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:04 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	do_ra_or_rb(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = ft_list_last(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

int	ra(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return (-1);
	do_ra_or_rb(stack);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return (-1);
	do_ra_or_rb(stack);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
	return (0);
}
