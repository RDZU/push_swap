/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:21:59 by razamora          #+#    #+#             */
/*   Updated: 2024/06/22 21:36:34 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (b > c && a < c)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if (a > b && b > c)
	{
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (a > b && b < c)
		ft_rotate(stack, 'a');
	else if (b > a && a > c)
		ft_rotate_reverse(stack, 'a');
	else if (c > b && b < a)
		ft_swap(stack, 'a');
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;
	int			contador;
	int			num_move_other_stack;

	current = *stack_a;
	contador = 0;
	num_move_other_stack = 0;
	while (num_move_other_stack <= 0)
	{
		if ((*stack_a)->index == 0)
		{
			push_other_stack(stack_a, stack_b, 'b');
			num_move_other_stack++;
		}
		else
			ft_rotate(stack_a, 'a');
	}
	ft_sort_three(stack_a);
	push_other_stack(stack_b, stack_a, 'a');
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;
	int			contador;
	int			num_move_other_stack;

	current = *stack_a;
	contador = 0;
	num_move_other_stack = 0;
	while (num_move_other_stack <= 1)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			push_other_stack(stack_a, stack_b, 'b');
			num_move_other_stack++;
		}
		else
			ft_rotate(stack_a, 'a');
	}
	ft_sort_three(stack_a);
	push_other_stack(stack_b, stack_a, 'a');
	push_other_stack(stack_b, stack_a, 'a');
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_swap(stack_a, 'a');
}