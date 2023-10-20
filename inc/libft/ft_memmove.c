/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:36:14 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/09 11:08:34 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (pdest > psrc)
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	else
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	return (dest);
}
/*
int	 main(void)
{

	char src[] ="bien 000000000000000000000000000000000000000";	
	char dest[]="Le cluster sift_size_listcieux c'est vraiment xxxx";

    	memmove(dest+37, src, 5);
	printf("memnouve = %s\n", dest);

	ft_memmove(dest+37, src, 5);
	printf("ft_memmouve =%s", dest);
        return (0);
}
*/
