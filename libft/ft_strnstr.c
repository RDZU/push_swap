/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:22 by razamora          #+#    #+#             */
/*   Updated: 2024/03/26 22:14:37 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	char		c;
	size_t		len_src;
	size_t		len_to_find;

	i = 0;
	len_src = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	c = to_find[0];
	if (len_to_find > len_src)
		return (0);
	else if (len_to_find == 0)
		return ((char *)str);
	while (str[i] != '\0' && (len_to_find + i) <= len)
	{
		if (str[i] == c)
		{
			if ((ft_strncmp(&str[i], to_find, len_to_find) == 0))
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
