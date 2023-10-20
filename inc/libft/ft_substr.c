/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:03:07 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/14 15:07:05 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*substrutilisée pour extraire une sous-chaîne d'une chaîne source 
reajuster la valeur de capture*/

char	*create_empty_string(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(sizeof(char));
	if (empty_str != NULL)
	{
		empty_str[0] = '\0';
	}
	return (empty_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t ft_size_list)
{
	size_t	i;
	size_t	s_ft_size_list;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_ft_size_list = ft_strlen(s);
	if (start >= s_ft_size_list)
		return (create_empty_string());
	if (ft_size_list > s_ft_size_list - start)
		ft_size_list = s_ft_size_list - start;
	substr = (char *)malloc(sizeof(char) * (ft_size_list + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_size_list)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
