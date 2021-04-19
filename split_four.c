#include "DO_NOT_OPEN/header.h"

size_t		ft_strlen(const char *s)
{
	size_t	i=0;
  
	while (s[i] != '\0')
		i++;
	return (i);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i =0;

	      
	if ((void *)src == NULL)
		return (0);
	if (size > 0)
	{
		while (src[i] && i<size - 1)
		{
			dst[i]=src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i]!='\0')
		i++;
	return i;
}
static size_t iter_chars(char const *s, char sep, size_t flag)
{
	size_t i =0;

	while (((s[i] == sep) == flag) && (s[i] != '\0')) i++;
	return (i);
}

static size_t    count_words(char const *s, char c)
{
	size_t 													flag=1;
	size_t words = 0;

	while (*s != '\0')
	{
		s+=iter_chars(s, c, flag);
		if (flag == 0) words++;
		flag =!flag;
	}
	return words;
}

static char	   **free_arr(char **arr, size_t len)
{
	size_t i;

	i=0;
	while (i < len) free(arr[i]); i++;
	free(arr);
	return ((char **)NULL);
}

static char			**fill_arr(char **arr, size_t len, char const *s, char sep)
{
	size_t leni = 0;
	size_t flag = 1;
	size_t i = 0;


	while (i < len && *s != '\0')
	{
		leni = iter_chars(s, sep, flag);
		if (flag == 0)
		{
			arr[i] = malloc((leni + 1) * sizeof(char)); 
			if (arr[i]==NULL)
				return (free_arr(arr, i));
			ft_strlcpy(arr[i], s, leni + 1);
			i++;
		}

		flag = !flag;
		s+=leni;
	}

	arr[i] = NULL;
	return(arr);
}

char                 **ft_split(char const *s, char c)
{
	size_t	nwords = 0;
	char	**out = NULL;



	if (s!=NULL)
	{
		nwords = count_words(s, c);
		out = malloc((nwords + 1) * sizeof(char *));
		if (out!=NULL)
			out = fill_arr(out, nwords, s, c);
	}
	return out;
}


void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}

