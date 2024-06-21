/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:31:24 by razamora          #+#    #+#             */
/*   Updated: 2024/03/24 11:42:03 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	act_len;
	char	*new;

	size = ft_strlen(s);
	act_len = 0;
	if (!s)
		return (NULL);
	if (size <= start)
		return (ft_calloc(1, sizeof(char)));
	act_len = size - start;
	if (act_len < len)
		len = act_len;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s[start], len + 1);
	return (new);
}
