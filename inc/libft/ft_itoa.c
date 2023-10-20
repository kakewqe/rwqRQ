/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:38:30 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/09 11:08:34 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_nb(int n)
{
	long	ft_size_list;

	ft_size_list = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ft_size_list++;
		n = -n;
	}	
	while (n != 0)
	{
		n = n / 10;
		ft_size_list++;
	}
	return (ft_size_list);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb_count;
	long	ft_size_list;

	nb_count = n;
	ft_size_list = ft_count_nb(nb_count);
	str = (char *)malloc((ft_size_list + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[ft_size_list] = '\0';
	ft_size_list--;
	if (nb_count < 0)
		nb_count = -nb_count;
	while (ft_size_list >= 0)
	{
		str[ft_size_list] = (nb_count % 10) + '0';
		nb_count = nb_count / 10;
		ft_size_list--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
