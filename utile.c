/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:45:20 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:00:32 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	is_sorted(t_list **a)
{
	t_list	*currant;

	if (*a == NULL)
		return (1);
	currant = *a;
	while (currant->next)
	{
		if (currant->value > currant->next->value)
			return (0);
		currant = currant->next;
	}
	return (1);
}

void	ft_free_pile(t_list **pile)
{
	t_list	*current;
	t_list	*next;

	current = *pile;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(pile);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

bool	ft_atoi_ps(const char *str, int *num)
{
	long long	rs;
	int			sg;

	rs = 0;
	sg = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		rs = rs * 10 + (*str++ - '0');
		if ((sg == 1 && rs > 2147483647LL)
			|| (sg == -1 && sg * rs < -2147483648LL))
			return (false);
	}
	*num = (int)(sg * rs);
	return (true);
}
