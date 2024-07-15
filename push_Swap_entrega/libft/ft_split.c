/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:17:14 by razamora          #+#    #+#             */
/*   Updated: 2024/03/24 12:50:21 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != (char)c && (*(s + 1) == (char)c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_count_lenght_split(char const *s, char c)
{
	size_t	end_pos;

	end_pos = 0;
	while (*s != '\0' && *s != (char)c)
	{
		s++;
		end_pos++;
	}
	return (end_pos);
}

static void	*ft_free_matrix(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		id_matrix;
	size_t		num_matrix;
	char		**words;

	if (!s)
		return (NULL);
	i = 0;
	id_matrix = 0;
	num_matrix = ft_count_word(s, c);
	words = (char **)malloc((num_matrix + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (id_matrix < num_matrix)
	{
		while (s[i] == c)
			i++;
		words[id_matrix] = ft_substr(s, i, ft_count_lenght_split(&s[i], c));
		if (!words[id_matrix])
			return (ft_free_matrix(words));
		i += ft_count_lenght_split(&s[i], c);
		id_matrix++;
	}
	words[num_matrix] = NULL;
	return (words);
}
