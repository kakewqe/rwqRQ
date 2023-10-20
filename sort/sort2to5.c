/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2to5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:45:36 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/18 19:14:32 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"
#include "../inc/push_swap.h"

void	sort_2(t_list **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_3(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->value < second->value && second->value < third->value)
		return ;
	else if (first->value < third->value && third->value < second->value)
	{
		sa(a);
		ra(a);
	}
	else if (second->value < first->value && first->value < third->value)
		sa(a);
	else if (second->value < third->value && third->value < first->value)
		ra(a);
	else if (third->value < first->value && first->value < second->value)
		rra(a);
	else if (third->value < second->value && second->value < first->value)
	{
		sa(a);
		rra(a);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	dist;
	int	min;

	if (is_sorted(stack_a))
		return ;
	min = get_min1(stack_a, -1);
	dist = get_dist(stack_a, min);
	if (dist == 1)
		sa(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	dist;
	int	min;

	min = get_min1(stack_a, -1);
	dist = get_dist(stack_a, min);
	if (dist == 1)
		sa(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (dist == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_1to2(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a))
		return ;
	size = ft_size_list(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
