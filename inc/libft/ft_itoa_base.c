/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:09:34 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/09 11:08:34 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_ft_size_list(long long nb, int base)
{
	int	ft_size_list;

	ft_size_list = 1;
	if (nb < 0 && base == 10)
	{
		ft_size_list += 1;
		nb = -nb;
	}
	while (nb / base > 0)
	{
		ft_size_list++;
		nb /= base;
	}
	return (ft_size_list);
}

static char	*allocate_result(int ft_size_list)
{
	char	*result;

	result = (char *)malloc((ft_size_list + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ft_size_list] = '\0';
	return (result);
}

static void	fill_result(char *result, long long nb, int base, int ft_size_list)
{
	const char	*digits;

	digits = "0123456789abcdef";
	while (nb != 0)
	{
		if (nb < 0 && base == 10)
			result[--ft_size_list] = digits[-(nb % base)];
		else
			result[--ft_size_list] = digits[nb % base];
		nb /= base;
	}
	if (nb < 0 && base == 10)
		result[0] = '-';
}

char	*ft_itoa_base(long long nb, int base)
{
	int		ft_size_list;
	char	*result;

	if (base < 2 || base > 16)
		return (NULL);
	ft_size_list = get_num_ft_size_list(nb, base);
	result = allocate_result(ft_size_list);
	if (!result)
		return (NULL);
	if (nb == 0)
	{
		result[0] = '0';
		return (result);
	}
	fill_result(result, nb, base, ft_size_list);
	return (result);
}
