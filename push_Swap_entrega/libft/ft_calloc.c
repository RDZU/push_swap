/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:01:34 by razamora          #+#    #+#             */
/*   Updated: 2024/03/17 16:25:42 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*new;
	size_t	num_bytes;

	num_bytes = nitems * size;
	new = malloc(num_bytes);
	if (!new)
		return (NULL);
	ft_bzero(new, num_bytes);
	return (new);
}
