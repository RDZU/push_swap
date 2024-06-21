/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:51:42 by razamora          #+#    #+#             */
/*   Updated: 2024/03/17 19:56:11 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	is_negative(int num)
{
	if (num < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	int		size;
	int		negative;
	char	*new;
	long	num;

	num = n;
	size = count_digit(num);
	negative = is_negative(num);
	new = (char *) malloc((size + negative + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (negative == 1)
	{
		num *= -1;
		new[0] = '-';
	}
	size += negative;
	new[size] = '\0';
	while (size-- != negative)
	{
		new[size] = (num % 10) + 48;
		num /= 10;
	}
	return (new);
}
