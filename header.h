#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define STRING "/o/ut of range /v/olume /-/ /1/loud th/j/s is"
#define PROMT "\033[0;41mThe answer consists of lines containing only one character. Good luck and... use your brain!\033[0;0m"

char    **ft_split(char const *s, char c);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
