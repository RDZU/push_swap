/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:03:37 by razamora          #+#    #+#             */
/*   Updated: 2024/03/16 21:03:33 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen(src);
	j = ft_strlen(dest);
	if (size == 0 || size < j)
		return (size + i);
	l = 0;
	k = j;
	while (src[l] != '\0' && l < size - 1)
	{
		if (j + l < size - 1)
		{
			dest[l + j] = src[l];
			k++;
		}
		l++;
	}
	dest[k] = '\0';
	return (i + j);
}
