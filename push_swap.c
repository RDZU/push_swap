/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:34:53 by razamora          #+#    #+#             */
/*   Updated: 2024/06/30 17:56:27 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_is_ordened(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;
	int		size_list;
	int		count_comparative;

	size_list = ft_size_list(head);
	if (size_list == 0)
		return ;
	i = head;
	j = i->next;
	if (size_list > 1)
	{
		count_comparative = 0;
		while (j != NULL)
		{
			if (j->content > i->content)
				count_comparative++;
			i = i->next;
			j = j->next;
		}
		if (count_comparative == size_list - 1)
			exit(0);
	}
}

void	ft_free_argv(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**words;
	int		*number;

	stack_a = NULL;
	stack_b = NULL;
	number = process_argv(argc, argv, &stack_a, words);
	if (argc == 1)
		ft_msm_error("", 0);
	ft_is_ordened(stack_a);
	ft_check_equal(stack_a);
	ft_sort_index(stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_lst_clear(&stack_a);
	ft_lst_clear(&stack_b);
	free(number);
}
