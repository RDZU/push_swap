/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:21:59 by razamora          #+#    #+#             */
/*   Updated: 2024/06/23 19:17:06 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;
	//ft_display(*stack);
	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	
	if ( a < b && b < c)
		return ;
	
	else if (a > b && b > c)
	{
		printf("\n caso 2");
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (a > b && c > b && c < a)
	{
		printf("\n caso 2.1");
		ft_rotate(stack, 'a');
	}
	// else if (a > b && b < c)
	// {
	// 	printf("\n caso 3");
	// 	ft_rotate(stack, 'a');
	// }
	if (b > a && a > c)
	{
		printf("\n caso 2.2");
		ft_rotate_reverse(stack, 'a');
	}
	else if (b > a && a < c)
	{
		printf("\n caso 4");
	//	ft_rotate_reverse(stack, 'a');
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if (c > a && a > b)
	{
		printf("\n caso 5");
		ft_swap(stack, 'a');
	}
	// else if (c > a && b > a)
	// {
	// 	printf("\n caso 6");
	// 	ft_rotate_reverse(stack, 'a');
	// }
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
	//ft_display(*stack_a);
	//ft_display(*stack_b);
	ft_sort_three(stack_a);
	//ft_display(*stack_a);
	push_other_stack(stack_b, stack_a, 'a');
	push_other_stack(stack_b, stack_a, 'a');
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_swap(stack_a, 'a');
}
