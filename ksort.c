/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:34:58 by razamora          #+#    #+#             */
/*   Updated: 2024/06/23 13:55:13 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ksort_part_one(t_stack **stack_a, t_stack **stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push_other_stack(stack_a, stack_b, 'b');
			ft_rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push_other_stack(stack_a, stack_b, 'b');
			i++;
		}
		else
			ft_rotate(stack_a, 'a');
	}
}

void	ksort_part_two(t_stack **stack_a, t_stack **stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(*stack_b, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != length - 1)
				ft_rotate(stack_b, 'b');
			push_other_stack(stack_b, stack_a, 'a');
			length--;
		}
		else
		{
			while ((*stack_b)->index != length - 1)
				ft_rotate_reverse(stack_b, 'b');
			push_other_stack(stack_b, stack_a, 'a');
			length--;
		}
	}
}
