/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:55:40 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:56 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include "inc/libft/libft.h"

/* Cree un elm */
t_list	*ft_new_list(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->lindex = -1;
	return (new);
}

/* Ajoute un elm au debut de la liste */
void	ft_list_add_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

/* Selectionne le dernier elem de la list */
t_list	*ft_list_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* Ajoute un elm a la fin de la list */
void	ft_list_add_back(t_list **stack, t_list *new)
{
	t_list	*z;

	if (*stack)
	{
		z = ft_list_last(*stack);
		z->next = new;
		new->next = NULL;
	}
	else
		*stack = new;
}

/* strft_size_list des listes chainees */
int	ft_size_list(t_list *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
/*
int main()
{
    t_list *mylist = NULL;

    t_list* node1 = ft_new_list(3);
    t_list* node2 = ft_new_list(1);
    t_list* node3 = ft_new_list(6);
    t_list* node4 = ft_new_list(100);
    t_list* node5 = ft_new_list(50);


    ft_list_add_back(&mylist, node4);
    ft_list_add_front(&mylist, node1);
    ft_list_add_front(&mylist, node2);
    ft_list_add_front(&mylist, node3);
    ft_list_add_back(&mylist, node5);

    printf("%i\n",ft_size_list(mylist));
    
    print_list(mylist);

    return 0;
}

*/