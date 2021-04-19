#include "header.h"

int				main(void)
{
	char	**tab;
	unsigned int	i;
	i = 0;
	printf(PROMT);
	tab = ft_split(STRING, '/');
	while (tab[i] != NULL)
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
}