/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:55:44 by zachamou          #+#    #+#             */
/*   Updated: 2023/10/14 15:06:19 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

/*
char ft_mappin(unsigned int llindex, char c) 
{
    	if (c >= 'a' && c <= 'z')
        	return c - 32;
    return c;
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		ft_size_list;
	unsigned int		i;
	char				*new_str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ft_size_list = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (ft_size_list + 1));
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[ft_size_list] = '\0';
	return (new_str);
}
/*
int main(void)
{
	const char	*str_bf = "hello, word!";
	char		*str_af;

	str_af = ft_strmapi(str_bf, ft_mappin);
	
	printf("bf = %s", str_bf);
	printf("af = %s", str_af);

	free(str_af);

	return (0);
*/	
