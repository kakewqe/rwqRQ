/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:17:14 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:21 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				lindex;
	struct s_list	*next;
}					t_list;

/*list.c*/
t_list				*ft_new_list(int value);
void				ft_list_add_front(t_list **stack, t_list *new);
t_list				*ft_list_last(t_list *stack);
void				ft_list_add_back(t_list **stack, t_list *new);
int					ft_size_list(t_list *stack);
void				print_list(t_list *stack);
/*op_*.c*/
void				do_sa_or_sb(t_list **stack);
int					sa(t_list **stack);
int					sb(t_list **stack);
int					ss(t_list **a, t_list **b);
void				do_ra_or_rb(t_list **stack);
int					ra(t_list **stack);
int					rb(t_list **stack);
int					rr(t_list **a, t_list **b);
void				do_rra_or_rrb(t_list **stack);
int					rra(t_list **stack);
int					rrb(t_list **stack);
int					rrr(t_list **a, t_list **b);
int					pa(t_list **a, t_list **b);
int					pb(t_list **a, t_list **b);
/*util.c, util.sort.c index_stack.c */
bool				ft_atoi_ps(const char *str, int *num);
void				initStack(t_list **stack, int argc, char **argv);
int					get_dist(t_list **stack, int val);
int					get_min1(t_list **stack, int val);
t_list				*search_index_min(t_list **stack);
void				get_index(t_list **stack);
/*Parsing*/
bool				check_params(int ac, char **av);
int					ft_error(char *str);
int					is_sorted(t_list **stack);
/*algo*/
void				sort_1to2(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b);
void				ft_free(char **str);
void				ft_free_pile(t_list **pile);

#endif
