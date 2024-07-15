/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:58:00 by razamora          #+#    #+#             */
/*   Updated: 2024/06/30 17:27:39 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_is_numeric(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str < 48 || *str > 57)
		ft_msm_error("Error", 1);
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			ft_msm_error("Error", 1);
		str++;
	}
}

void	ft_check_equal(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;

	i = head;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->content == j->content)
				ft_msm_error("Error", 1);
			j = j->next;
		}
		i = i->next;
	}
}

int	ft_check_string(const char *str)
{
	long	result;

	ft_is_numeric(str);
	if (ft_strlen(str) > 11)
		ft_msm_error("Error", 1);
	result = ft_atoi_check(str);
	return (result);
}

void	ft_check_range(long number)
{
	if (number < -2147483648 || number > 2147483647)
		ft_msm_error("Error", 1);
}
