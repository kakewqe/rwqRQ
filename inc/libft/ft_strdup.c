/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:44:54 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/16 13:03:59 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Elle commence par Alloue de l'espace pour une nouvelle chaîne,
en définissant la même taille que la chaîne d'origine puis Copie
la chaîne d'origine dans le nouvel espace alloué, y compris
le caractère nul ( \0)
*/

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		j;
	int		i;

	if (s == NULL || *s == '\0')
		return (NULL);
	j = 0;
	j = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*dup;
	char	*dup2;
	int		o_ft_size_list;
	int		d_ft_size_list;

	char src[12] = "Ooga booga!";
	dup = ft_strdup(src);
	dup2 = strdup(src);
	o_ft_size_list = strft_size_list(dup2);
	d_ft_size_list = strft_size_list(dup);
	printf("Original Strdup = %s (%d)\n", dup2, o_ft_size_list);
	printf("My fonction strdup = %s (%d)\n", dup, d_ft_size_list);
	free(dup);
	free(dup2);
	return (0);
}
*/
