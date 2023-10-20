/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:22:58 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/14 15:06:33 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*strtrim est utilisée pour supprimer les caractères de début et de fin 
*on avance tant que l'on recontre nos occurence */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	ft_size_list;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	ft_size_list = end - start + 1;
	str = (char *)malloc(ft_size_list * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, ft_size_list);
	return (str);
}
/*initialisation de ft_size_list apres cutindice */
