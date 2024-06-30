/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:50:36 by razamora          #+#    #+#             */
/*   Updated: 2024/06/30 17:35:14 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	count_r(t_stack *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

int	ft_sqrt(int number)
{
	int	result;

	result = 1;
	while (result * result < number)
		result++;
	return (result);
}

int	ft_atoi_check(const char *str)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
		ft_msm_error("Error", 1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	result = result * sign;
	ft_check_range(result);
	return (result);
}

void	ft_msm_error(char *str, int flag)
{
	while (*str != '\0')
	{
		write (1, str++, 1);
	}
	write(1, "\n", 1);
	exit(flag);
}
