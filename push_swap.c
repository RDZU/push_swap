#include "push_swap.h"
#include <math.h>

int	ft_lstsize(t_stack *lst);
//int	ft_lstsize(t_stack *lst);
int	count_r(t_stack *stack, int index);
void	ksort_part_one(t_stack *stack_a, t_stack *stack_b, int length);
void	ksort_part_two(t_stack *stack_a, t_stack *stack_b, int length);
t_stack	*ft_lstlast(t_stack *lst);
void ft_sort_three(t_stack **stack);
void ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void ft_sort(t_stack **stack_a, t_stack **stack_b, int size_list);
int	ft_atoi(const char *str);
int ft_size_list(t_stack *head);
void ft_push(t_stack **before, int content, int pos);
int ft_check_equal( t_stack *head);
int	ft_is_sort(t_stack *head);
void	ft_sort_index(t_stack *head);
void ft_display(t_stack *n);
void	ft_rotate_reverse(t_stack **list, char type);
void ft_rotate(t_stack **list, char type);
void	push_other_stack(t_stack **a, t_stack **b, char type);
void ft_swap(t_stack **list, char type);
// ORDENAMIENTO


int	ft_lstsize(t_stack *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

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
void	ksort_part_one(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = sqrt(length) * 14 / 10;
	while (stack_a)
	{
		if (stack_a->index <= i)
		{
			push_other_stack(&stack_a, &stack_b, 'b');
			ft_rotate(&stack_b, 'b');
			i++;
		}
		else if (stack_a->index <= i + range)
		{
			push_other_stack(&stack_a, &stack_b, 'b');
			i++;
		}
		else
			ft_rotate(&stack_a, 'a');
	}
}


void	ksort_part_two(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->index != length - 1)
				ft_rotate(&stack_b, 'b');
			push_other_stack(&stack_b, &stack_a, 'a');
			length--;
		}
		else
		{
			while (stack_b->index != length - 1)
				ft_rotate_reverse(&stack_b, 'b');
			push_other_stack(&stack_b, &stack_a, 'a');
			length--;
		}
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//void push (t_stack a, t_stack b )
void	ft_rotate_reverse(t_stack **list, char type)
{
	t_stack		*first;
	t_stack		*aux;
	t_stack		*last;

	if (!list || !(*list)->next)
		return ;
	
	first = (*list);
	last = ft_lstlast(*list);
	aux = *list;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	last->next = first;
	*list = last;
	if (type == 97)
		write(1,"rra\n",4);
	if (type == 98)
		write(1,"rrb\n",4);


}

void ft_rotate(t_stack **list, char type)
{
	t_stack		*last;
	t_stack		*first;
	
	if (!list || !*list)
		return ;
	first = (*list);
	last = ft_lstlast(*list);
	*list = (*list)->next;
	last->next = first;
	first->next = NULL;
	if (type == 97)
		write(1,"ra\n",3);
	if (type == 98)
		write(1,"ra\n",3);
}



void	push_other_stack(t_stack **a, t_stack **b, char type)
{
	t_stack *aux;
	t_stack *new;
	int		content;
	int		index;
	int		pos;

	if (!a || !b)
		return;
	aux = *a;
	content = aux->content;
	index = aux->index;
	pos = aux->pos;
	*a = aux->next;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return;
	new->content = content;
	new->index = index;
	new->pos = pos;
	new->next = *b;
	*b = new;
	if (type == 97)
		write(1,"pa\n",3);
	if (type == 98)
		write(1,"pb\n",3);
}

void	push_other_stack_a(t_stack **a, t_stack **b)
{
	t_stack *aux;
	t_stack *new;
	int		content;
	int		index;

	if (!a || !b)
		return;
	aux = *b;
	content = aux->content;
	index = aux->index;
	*b = aux->next;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return;
	new->content = content;
	new->index = index;
	new->pos = 1;
	new->next = *a;
	*a = new;
	write(1,"pb\n",3);
}


void ft_swap(t_stack **list, char type)
{
	t_stack *aux;

	if (!list || !(*list)->next)
		return ;
	aux = *list;
	*list = (*list)->next;
	aux->next = (*list)->next;
	(*list)->next = aux;
	if (type == 97)
		write(1,"sa\n",3);
	if (type == 98)
		write(1,"sb\n",3);
}

void ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;

	if(b > c && a < c)
	{
		printf("\n caso 1");
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if (a > b && b > c)
	{
		printf("\n caso 2");
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (b > a && a > c)
	{
		printf("\n caso 3");
		ft_rotate_reverse(stack, 'a');
		
	}
	else if(c > b && b < a)
	{
		printf("\n caso 4");
		ft_swap(stack, 'a');
	}
}

void ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current = *stack_a;
	int contador = 0;
	int	num_move_other_stack = 0;

		while (num_move_other_stack <= 1)
		{
		//	printf(" | contenido------>>>>>>: %d | ", (*stack_a)->content);
			if ((*stack_a)->index == 0  || (*stack_a)->index == 1)
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
	{
		ft_swap(stack_a, 'a');
	}
}


void ft_sort(t_stack **stack_a, t_stack **stack_b, int size_list)
{
	// printf("\n size_list: %d \n", size_list);
	// // verificas si esta ordenado
	// if (size_list == 2)
	// {
	// 	ft_swap(a,'a');
	// }
	// else if (size_list == 3)
	// {
	// 	ft_sort_three(a);
	// }
	// else if(size_list == 5)
	// {
	// 	ft_sort_five(a, b);
	// }
	// else if (size_list > 5)
	// {
	// 	//   ksort_part_one(*(a), *(b), size_list);
	// 	//   ksort_part_two(*(a), *(b), size_list);
	// }	


		int	i;
	int	range;
		int	rb_count;
	int	rrb_count;

	i = 0;
	range = sqrt(size_list) * 14 / 10;
		printf(" | contenido------>>>>>>");
		//exit(1);
	while ((*stack_a))
	{
		printf(" | contenido------>>>>>>: %d | ", (*stack_a)->content);
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
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

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
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int ft_size_list(t_stack *head)
{
	int pos;
	if (!head)
		return (0);

	while (head != NULL)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}
				// node 1 			node 2
void ft_push(t_stack **before, int content, int pos)
{
	t_stack *new;

	if (!before)
		return;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return;
	
	new->content = content;
	new->index = 0;
	new->pos = pos;
	new->next = *before;
	*before = new;
}


// ft_replace(argv)
// {

// }

//void ft_swap()
//void push
// voud rotate
// void reverse
//void rrr
// int	ft_doble_char(char *str)
// {
// 	int i;
// 	int	j;
	
// 	i = 0;
// 	while(i < strlen(str))
// 	{
// 		j = i + 1;
// 		while(j < strlen(str))
// 		{
// 		  	if(str[i] == str[j])
// 				return (1);
// 		  	j++;
// 		}
// 		i++;
// 	  }
// 	return (0);
// }

int ft_check_equal( t_stack *head)
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
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
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
void	ft_sort_index(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	index = 0;
	i = head;
	
	while (i != NULL)
	{
		j = i->next;
		while(j != NULL)
		{
			if (i->content > j->content)
				i->index += 1;
			else if (i->content < j->content) 
				j->index += 1;
			j = j->next;
		}
		i = i->next;
	}
}
void ft_display(t_stack *n)
{
	int count = 0;
	while(n != NULL)
	{
		printf(" | contenido: %d | ", n->content);
		printf(" index: %d | ", n->index);
		printf(" pos: %d | ", n->pos);
		printf(" dir. actual: %p | ", n);
		printf(" dir. apunta: %p | ", n->next);
		printf(" count: %d | \n", count++);
		 n = n->next;
	}
}
int main (int argc, char **argv)
{	
	 t_stack *stack_a = NULL;
	 t_stack *stack_b = NULL; 
	 int i = argc;

	if (argc >= 2)
	{
		while (--i > 0)
		{
			ft_push(&stack_a,ft_atoi(argv[i]),i);
		}
		//printf("%d\n", ft_check_equal(stack_a));
		//ft_is_sort(stack_a);
		printf("Esta Ordenado:");
		//ft_is_sort(stack_a);
		ft_sort_index(stack_a);
		//ft_swap(&head);
		//ft_rotate(&stack_a);
		//ft_rotate_reverse(&stack_a);
		//ft_swap(&head);
		//ft_swap(&head);
		// push_other_stack(&stack_a, &stack_b);
		// push_other_stack(&stack_a, &stack_b);
		// push_other_stack(&stack_a, &stack_b);

		ft_sort(&stack_a, &stack_b, argc - 1);
		printf("\n Stack a \n");
		ft_display(stack_a);
		printf("Stack b \n");
		ft_display(stack_b);
		free(stack_a);
		free(stack_b);
	}
}


///void ft_printf()
// int main ()
// {
// 	struct t_list *head = NULL;

// 	int a = 1337;
// 	int b = 80;
// 	int c = 80;

// 	void *pa = &a;
// 	void *pb = &b;
// 	void *pc = &c;

// 	t_list * node1 = ft_lstadd(pa);
// 	head = node1;

// 	t_list *node2 = ft_lstnew(pb);
// 	ft_lstadd_front(&head, node2);

// 	t_list *node3 = ft_lstnew(pc);
// 	ft_lstadd_front(&head, node3);

// 	ft_display(head);

// 	return 0;
// }