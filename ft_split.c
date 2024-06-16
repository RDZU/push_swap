
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


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

size_t    ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t    i;

    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while (src[i] != '\0' && i < size - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    i = 0;
    while (src[i] != '\0')
        i++;
    return (i);
}


char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t    size;
    size_t    act_len;
    char    *new;

    size = ft_strlen(s);
    act_len = 0;
    if (!s)
        return (NULL);
    if (size <= start)
        return (calloc(1, sizeof(char)));
    act_len = size - start;
    if (act_len < len)
        len = act_len;
    new = (char *)malloc((len + 1) * sizeof(char));
    if (!new)
        return (NULL);
    ft_strlcpy(new, &s[start], len + 1);
    return (new);
}

static size_t    ft_count_word(char const *s, char c)
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

static size_t    ft_count_lenght_split(char const *s, char c)
{
    size_t    end_pos;

    end_pos = 0;
    while (*s != '\0' && *s != (char)c)
    {
        s++;
        end_pos++;
    }
    return (end_pos);
}

static void    *ft_free_matrix(char **mat)
{
    size_t    i;

    i = 0;
    while (mat[i])
        free(mat[i++]);
    free(mat);
    return (NULL);
}

char    **ft_split(char const *s, char c)
{
    size_t        i;
    size_t        id_matrix;
    size_t        num_matrix;
    char        **words;

    if (!s)
        return (NULL);
    i = 0;
    id_matrix = 0;
    num_matrix = ft_count_word(s, c);
    words = (char **)malloc((num_matrix + 1) * sizeof(char *));
    if (!words)
        return (NULL);
    while (id_matrix < num_matrix)
    {
        while (s[i] == c)
            i++;
        words[id_matrix] = ft_substr(s, i, ft_count_lenght_split(&s[i], c));
        if (!words[id_matrix])
            return (ft_free_matrix(words));
        i += ft_count_lenght_split(&s[i], c);
        id_matrix++;
    }
    words[num_matrix] = NULL;
    return (words);
}

int main (int argc, char **argv)
{
    char **s_number;
    int i = 0;
    int j = argc - 1;
    
    while (++i < argc)
	{
		s_number = ft_split(argv[i], ' ');
		// while (s_numbers[k])
		// 	numbers[j++] = ft_atoi(s_numbers[k++]);
		// free_2d(s_numbers);
         printf("%s\n", s_number[i]);
	}
    i = 0;
    // while(s_number[i])
    // {
    //     printf("%s\n", s_number[i]);
    //     free(s_number[i]);
    //     i++;
    // }
    // free(s_number);
    return (0);
}

/*analisis**/
