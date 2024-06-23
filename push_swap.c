/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:34:53 by razamora          #+#    #+#             */
/*   Updated: 2024/06/23 18:23:56 by razamora         ###   ########.fr       */
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
	size_list = ft_size_list(head);
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

void	ft_free_matrix(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

void ft_display(t_stack *n)
{
	char *file = "swap.log";
	 FILE *fp = fopen(file, "w"); // Open file in write mode
	if (fp == NULL) {
		printf("Error: Cannot open file for writing!\n");
		return;
	}
	int count = 0;
	while(n != NULL)
	{
		fprintf(fp, " | contenido: %d | ", n->content);
		fprintf(fp, " index: %d | ", n->index);
		fprintf(fp, " pos: %d | ", n->pos);
		fprintf(fp, " dir. actual: %p | ", (void *)n); // Cast 
		fprintf(fp, " dir. apunta: %p |\n ", (void *)n->next); // Cast
		//fprintf(fp, " count: %d | \n", count++);
		 n = n->next;
	}
	fprintf(fp, "\n \n");
	fclose(fp);
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
	ft_display(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	free(number);
}
