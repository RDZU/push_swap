#include "push_swap.h"
#include <fcntl.h>

int		ft_lstsize(t_stack *lst);
//int	ft_lstsize(t_stack *lst);
int		count_r(t_stack *stack, int index);
void	ksort_part_one(t_stack **stack_a, t_stack **stack_b, int length);
void	ksort_part_two(t_stack **stack_a, t_stack **stack_b, int length);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size_list);
int		ft_atoi(const char *str);
int		ft_size_list(t_stack *head);
void	ft_push(t_stack **before, int content, int pos);
void	ft_check_equal( t_stack *head);
int		ft_is_sort(t_stack *head);
void	ft_sort_index(t_stack *head);
void	ft_display(t_stack *n);
void	ft_rotate_reverse(t_stack **list, char type);
void	ft_rotate(t_stack **list, char type);
void	push_other_stack(t_stack **a, t_stack **b, char type);
void	ft_swap(t_stack **list, char type);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
//void	ft_is_numeric(char *str);
int		ft_is_numeric(char *str);
void	ft_is_ordened(t_stack *head);
void	ft_msm_error(char *str, int flag);
size_t	ft_strlen(const char *s);

// ORDENAMIENTO

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}
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
void	ksort_part_one(t_stack **stack_a, t_stack **stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = sqrt(length) * 14 / 10;
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
	//printf("\n size_list: %d \n", size_list);
	// verificas si esta ordenado
	if (size_list == 2)
	{
		if((*stack_a)->index > (*stack_a)->next->index)
			ft_swap(stack_a,'a');
	}
	else if (size_list == 3)
	{
		ft_sort_three(stack_a);
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

void ft_sort_ksort(t_stack **stack_a, t_stack **stack_b, int size_list)
{
	int	i;
	int	range;
	int	rb_count;
	int	rrb_count;

	i = 0;
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
int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_strlen(str) > 11)
		ft_msm_error("max 12 strlen", 1);
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
	result = result * sign;
	//printf("--> %ld", result);
	if (result < -2147483648 || result > 2147483647)
		ft_msm_error("outside range",1);
	// if (-2147483648  < result)
	// 	ft_msm_error("outside range",1);
	return (result);
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

void ft_free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}
				// node 1 			node 2
void ft_push(t_stack **before, int content, int pos)
{
	t_stack *new;

	if (!before)
		return;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{	
		ft_free_stack(&new);
	}
	new->content = content;
	new->index = 0;
	new->pos = pos;
	new->next = *before;
	*before = new;
}
void	ft_msm_error(char *str, int flag)
{
	while (*str != '\0')
		write(1, str++, 1);
	exit(flag);
}
int	ft_is_numeric(char *str)
{
	if(*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		if (*str < 48 || *str > 57)
			return (0);
		str++;
	}
	return (1);
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
			printf("i: %d, j:%d \n",i->content, j->content);
			if (i->content == j->content)
				ft_msm_error("repeat Error",1);
			j = j->next;
		}
		i = i->next;
	}
}
// void ft_is_ordened(t_stack *head)
// {
// 	t_stack *i;
// 	t_stack *j;

// 	i = head;
// 	while (i != NULL )
// 	{
// 		j = i->next;
// 		while (j != NULL && j->next != NULL)
// 		{
// 			if (i->content > j->content)
// 			j = j->next;
// 		}
// 		i = i->next;
// 	}
// }

void ft_is_ordened(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;
	int		size_list;
	int		count_comparative;

	i = head;
	j = i->next;

	size_list = ft_lstsize(head);
	if (size_list > 1)
	{
	count_comparative = 0;
		while (j != NULL)
		{
			if (j->content > i->content)
				count_comparative++;
			//printf("i-> %d, j->%d \n", i->content, j->content);
			i = i->next;
			j = j->next;
		}
		//printf("count-> %d, size-> %d \n", count_comparative,size_list - 1);
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

int	ft_count_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_is_numeric(&argv[i][j]))
				return (-1);
			if (ft_is_numeric(&argv[i][j]) && (argv[i][j + 1] == ' ' ||  argv[i][j + 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
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
		fprintf(fp, " dir. actual: %p | ", (void *)n); // Cast for compatibility
		fprintf(fp, " dir. apunta: %p |\n ", (void *)n->next); // Cast for compatibility
		//fprintf(fp, " count: %d | \n", count++);
		 n = n->next;
	}
}
int main (int argc, char **argv)
{	
	 t_stack *stack_a = NULL;
	 t_stack *stack_b = NULL;
	 int	result_atoi;
	 int i = argc;
	 int number;
	 int count_argc;
	 int *number_array;

	

	if (argc >= 2)
	{
		count_argc = ft_count_digits(argc, argv);

		printf(" count -->%d", count_argc);
		exit(0);
		while (--i > 0)
		{
			ft_is_numeric(argv[i]);
			number_array = ft_split(argc, argv);
			//printf(" result atoi: %s \n", argv[i]);
			result_atoi = ft_atoi(argv[i]);
			//printf(" result atoi: %d \n", result_atoi);
			ft_push(&stack_a, result_atoi, i);
		}
		ft_is_ordened(stack_a);
		// if (is_sort == 1)
		// 	write(1,"repeat",6);
		ft_check_equal(stack_a);
		ft_sort_index(stack_a);
		//printf("%d\n", ft_check_equal(stack_a));
		//ft_is_sort(stack_a);
		//printf("Esta Ordenado:");
		//exit(1);
		//ft_swap(&head);
		//ft_rotate(&stack_a);
		//ft_rotate_reverse(&stack_a);
		//ft_swap(&head);
		//ft_swap(&head);
		// push_other_stack(&stack_a, &stack_b);
		// push_other_stack(&stack_a, &stack_b);
		// push_other_stack(&stack_a, &stack_b);
		//if (argc - 1 <= 5)
		ft_sort(&stack_a, &stack_b, argc - 1);
		ft_display(stack_a);
		// else
		// 	ft_sort_ksort(&stack_a, &stack_b, argc - 1);
		//printf("\n Stack a \n");
		//printf("Stack b \n");
		//ft_display(stack_b);
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