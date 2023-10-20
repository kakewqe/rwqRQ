/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:44:03 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:07 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	do_sa_or_sb(t_list **stack)
{
	t_list	*frist;
	t_list	*second;
	int		temp;
	int		temp_lindex;

	if (!*stack || !(*stack)->next)
		return ;
	frist = *stack;
	second = frist->next;
	temp = frist->value;
	frist->value = second->value;
	second->value = temp;
	temp_lindex = frist->lindex;
	frist->lindex = second->lindex;
	second->lindex = temp_lindex;
}

int	sa(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return (-1);
	do_sa_or_sb(stack);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return (-1);
	do_sa_or_sb(stack);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return (-1);
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 1);
	return (0);
}
