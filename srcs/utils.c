#include "../inc/RushWordle.h"

int ft_str_isalpha(char *str)
{
	for (int i = 0; i < 5; i++)
	{
		if (isalpha(str[i]) == 0)
			return (-1);
	}
	return 0;
}

void	clean(t_grid grid/*, t_word index*/)
{
	int i;
	
	i = -1;
	while (grid.tab[++i])
		free(grid.tab[i]);
	free(grid.tab);
	free(grid.word);
}
