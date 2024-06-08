#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


// char	*ft_substr(char const *s, unsigned int start, size_t len);
// static void	*ft_free_matrix(char **mat)
// static size_t	ft_count_lenght_split(char const *s, char c)
// ⌂ static size_t	ft_count_word(char const *s, char c)
// ⌂ static size_t    ft_count_lenght_split(char const *s, char c)
// static size_t    ft_strlcpy(char *dest, const char *src, size_t size)
// static void    *ft_free_matrix(char **mat) ⌂

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
static int ft_strlcpy(char *dest, const char *src, size_t size)
{
    int i;

    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while (src [i] != '\0' && i < size - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
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
        // 10 15
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


char	*ft_substr2(char const *s, unsigned int start, size_t len)
{

}

static void    *ft_free_matrix(char **mat)
{
    int i = 0;
    while (mat[i])
    {
        free(mat[i]);
        i++;
    }
    free(mat);
    return (NULL);
}



static int ft_count_lenght_split(char const *s, char c)
{
    int end = 0;
    int i = 0;
    while (s[i] != '\0' && s[i] != c)
    {
        end++;
        i++;
    }
    return end;
}

static int   ft_count_word(char *str, char sep)
{
    int i = 0;
    int count = 0;
    while(str[i] == sep)
        i++;
    while (str[i] != '\0')
    {
        if (str[i] == sep && str[i + 1] != sep || str[i + 1] == '\0' )
            count++;
        i++;
    }
    return (count);
}
char    **ft_split(char *str)
{

}


int main ()
{
    // char **words;
    // int i = 0;

    // words = ft_split("la casa es ");
    // while(words)
    // {
    //     printf("%s\n", words[i]);
    //     free(words[i]);
    //     i++;
    // }
    // free(words);
    // return (0);
    char c[] = "la casa blanca";
    char x[] = "razamora";
    //*ft_substr(char const *s, unsigned int start, size_t len);
    printf("%s",ft_substr(c,3,10));

}
