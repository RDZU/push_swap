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
