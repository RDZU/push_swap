/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:01:32 by razamora          #+#    #+#             */
/*   Updated: 2024/06/23 19:37:09 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_list;

	size_list = ft_size_list(*stack_a);
	if (size_list == 2)
		ft_swap(stack_a, 'a');
	else if (size_list == 3)
		ft_sort_three(stack_a);
	else if (size_list == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size_list == 5)
		ft_sort_five(stack_a, stack_b);
	else if (size_list > 5)
	{
		ksort_part_one(stack_a, stack_b, size_list);
		ksort_part_two(stack_a, stack_b, size_list);
	}
}

int	ft_calculate_number_elem(int argc, char **argv)
{
	int	total_words;
	int	i;

	i = 1;
	total_words = 0;
	while (i < argc)
		total_words += ft_count_word(argv[i++], ' ');
	return (total_words);
}

int	*process_argv(int argc, char **argv, t_stack **stack_a, char **words)
{
	int	*number;
	int	i;
	int	k;
	int	j;

	i = 1;
	j = 0;
	k = ft_calculate_number_elem(argc, argv);
	number = (int *)malloc(sizeof(int) * k);
	if (!number)
		return (0);
	while (i < argc)
	{
		words = ft_split(argv[i++], ' ');
		k = 0;
		while (words[k])
			number[j++] = ft_check_string(words[k++]);
		ft_free_matrix(words);
	}
	while (j-- > 0)
		ft_push(stack_a, number[j], j);
	return (number);
}

size_t	ft_count_word(char const *s, char c)
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
