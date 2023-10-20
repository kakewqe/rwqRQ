/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:59:52 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/14 15:02:11 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	size_t	ft_size_list;

	if (s != NULL)
	{
		ft_size_list = ft_strlen(s);
		write(fd, s, ft_size_list);
	}
}

/*
int main(void)
{
	char *str = "trstfdfd";
	int fd = 1;
	
	ft_putstr_fd(str, fd);
}
*/
