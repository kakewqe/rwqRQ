/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:45:13 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/19 21:45:36 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	init_stack(t_list **stack, int ac, char **params)
{
	t_list	*new;
	int		num;
	int		i;

	i = 0;
	if (ac == 1)
		params = ft_split(params[0], ' ');
	while (params[i])
	{
		ft_atoi_ps(params[i], &num);
		new = ft_new_list(num);
		ft_list_add_back(stack, new);
		i++;
	}
	get_index(stack);
	if (ac == 1)
		ft_free(params);
}

void	check_list(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
	{
		ft_free_pile(stack_a);
		ft_free_pile(stack_b);
		exit(0);
	}
	if (ft_size_list(*stack_a) <= 5)
		sort_1to2(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;

	if (ac < 2)
		return (EXIT_FAILURE);
	if (!check_params(ac - 1, av + 1))
	{
		ft_error("Error");
		exit(1);
	}
	a = (t_list **)malloc(sizeof(t_list *));
	b = (t_list **)malloc(sizeof(t_list *));
	if (a == NULL || b == NULL)
		exit(1);
	*a = NULL;
	*b = NULL;
	init_stack(a, ac - 1, av + 1);
	check_list(a, b);
	ft_free_pile(a);
	ft_free_pile(b);
	return (0);
}
