/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:45:05 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/20 17:01:34 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	ft_vdouble(char **av, int num, int idx)
{
	int	num2;

	idx++;
	while (av[idx])
	{
		if (ft_atoi_ps(av[idx], &num2)&& num == num2)
			return (1);
		idx++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	check_params_er(char **parms)
{
	int	num;
	int	i;

	i = 0;
	while (parms[i])
	{
		if (!ft_atoi_ps(parms[i], &num)
			|| !ft_isnum(parms[i])
			|| ft_vdouble(parms, num, i))
			return (false);
		i++;
	}
	return (true);
}

bool	check_less(char **av)
{
	int	j;

	j = 0;
	while (av[j])
	{
		if (av[j][0] == '-' && ft_isdigit(av[j][1]) == 0)
			return (false);
		j++;
	}
	return (true);
}

bool	check_params(int ac, char **params)
{
	bool	status;

	if (ac == 1)
	{
		params = ft_split(params[0], ' ');
		if (!params)
			return (false);
	}
	status = check_less(params)
			&& check_params_er(params);
	if (ac == 1)
		ft_free(params);
	return (status);
}
