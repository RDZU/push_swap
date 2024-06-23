/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:34:58 by razamora          #+#    #+#             */
/*   Updated: 2024/06/22 23:50:00 by razamora         ###   ########.fr       */
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
		//	if(!(*stack_a)->index <= i + range)
		//		ft_rotate_both(stack_a,stack_b);
		//	else
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
			//printf(" | contenido------>>>>>>: %d | \n", (*stack_b)->content);
			//printf(" | len------>>>>>>: %d | \n", length);
		//	if( !(*stack_b))
		//		printf("test");
				
			while ((*stack_b)->index != length - 1)//error
			{
		//		printf("linea \n");
				ft_rotate(stack_b, 'b');
			}
			push_other_stack(stack_b, stack_a, 'a');
			length--;
		}
		else
		{
		//	if( !(*stack_b))
		//		printf("test 2");
			while ((*stack_b)->index != length - 1)
				ft_rotate_reverse(stack_b, 'b');
			push_other_stack(stack_b, stack_a, 'a');
			length--;
		}
	}
}

/*
void ft_sort_ksort(t_stack **stack_a, t_stack **stack_b, int size_list)
{
	int	i;
	int	range;
	int	rb_count;
	int	rrb_count;

	i = 0;
	range = sqrt(size_list) * 14 / 10;
	range = sqrt(size_list) * 14 / 10;
		//printf(" | contenido------>>>>>>");
		//exit(1);
	while ((*stack_a))
	{
		//printf(" | contenido------>>>>>>: %d | ", (*stack_a)->content);
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

	while (size_list - 1 >= 0)
	{
		rb_count = count_r(*stack_b, size_list - 1);
		rrb_count = (size_list + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != size_list - 1)
				ft_rotate(stack_b, 'b');
			push_other_stack(stack_b, stack_a, 'a');
			size_list--;
		}
		else
		{
			while ((*stack_b)->index != size_list - 1)
				ft_rotate_reverse(stack_b, 'b');
			push_other_stack(stack_b, stack_a, 'a');
			size_list--;
		}
	}
}
*/
