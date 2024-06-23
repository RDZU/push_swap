/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:34:53 by razamora          #+#    #+#             */
/*   Updated: 2024/06/23 02:27:18 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


// ORDENAMIENTO





void ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	//printf("\n size_list: %d \n", size_list);
	// verificas si esta ordenado
	int	size_list;
	size_list = ft_size_list(*stack_a);
	//printf(" %d",size_list );exit(1);
	if (size_list == 2)
	{
		if((*stack_a)->index > (*stack_a)->next->index)
			ft_swap(stack_a,'a');
	}
	else if (size_list == 3)
	{
		ft_sort_three(stack_a);
	}
	else if (size_list == 4)
	{
		ft_sort_four(stack_a, stack_b);
	}
	else if(size_list == 5)
	{
		ft_sort_five(stack_a, stack_b);
	}
	else if (size_list > 5)
	{
		   ksort_part_one(stack_a, stack_b, size_list);
		   ksort_part_two(stack_a, stack_b, size_list);
	}	
}
void	ft_is_numeric(const char *str)
{
	if(*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			ft_msm_error("Error is not numeric",1);
		str++;
	}
	
}

void	ft_check_equal( t_stack *head)
{
	t_stack	*i;
	t_stack	*j;

	i = head;
	
	while (i != NULL)
	{
		j = i->next;
		while(j != NULL)
		{
			if (i->content == j->content)
				ft_msm_error("repeat Error",1);
			j = j->next;
		}
		i = i->next;
	}
}

void ft_is_ordened(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;
	int		size_list;
	int		count_comparative;

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


int	ft_is_sort(t_stack *head)
{
	t_stack *i;
	t_stack *j;

	i = head;
	while (i != NULL)
	{
		j = i->next;
		while(j != NULL && j->next != NULL)
		{
			if (i->content > j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return(0);
}

void ft_display(t_stack *n)
{
	char *file = "swap.log";
	 FILE *fp = fopen(file, "a"); // Open file in write mode
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
		fprintf(fp, " dir. actual: %p | ", (void *)n); // Cast for compatibility
		fprintf(fp, " dir. apunta: %p |\n ", (void *)n->next); // Cast for compatibility
		//fprintf(fp, " count: %d | \n", count++);
		 n = n->next;
	}
	fprintf(fp, "\n \n");
	fclose(fp);
}


size_t    ft_count_word(char const *s, char c)
{
	size_t    count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != (char)c && (*(s + 1) == (char)c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}




void	ft_checker(t_stack **lst)
{
	
}

int 	*process_argv(int argc, char **argv, t_stack **stack_a, char **words)
{
	int	*number;
	int i;
	int k;
	int j;

	k = 0;
	i = 1;
	j = 0;
	while(i < argc)
		k = k + ft_count_word(argv[i++], ' ');
	i = 1;
	number = (int *)malloc(sizeof(int) * k);
	if(!number)
		return 0;
	while (i < argc)
	{
		words = ft_split(argv[i++],' ');
		k = 0;
		while (words[k])
			number[j++] = ft_atoi(words[k++]);
		ft_free_matrix(words);
	}
	while (j-- > 0)
		ft_push(stack_a,number[j],j);
	return (number);
}

int main (int argc, char **argv)
{	
	 t_stack *stack_a = NULL;
	 t_stack *stack_b = NULL;
	char **words;
	int *number;

	number = process_argv(argc,argv, &stack_a,words);
	if (argc == 1)
		ft_msm_error("",0);

	ft_is_ordened(stack_a);
	ft_check_equal(stack_a);
	ft_sort_index(stack_a);
	ft_sort(&stack_a, &stack_b);
	//ft_display(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	free(number);
}




// 1% ARG="17 4 11 6 9 14 18 3 12 8 5 7 10 16 20 15 2 13 1 19"; ./a.out $ARG > result.txt  

// https://push-swap-visualizer.vercel.app/
