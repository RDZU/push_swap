/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:51:57 by razamora          #+#    #+#             */
/*   Updated: 2024/03/22 20:32:10 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s2 = src;
	s1 = dst;
	if (!s1 && !s2)
		return (NULL);
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	else
	{
		while (n--)
			s1[n] = s2[n];
	}
	return (s1);
}
