#include "../inc/RushWordle.h"

t_grid	initGridGame(char *guess)
{
	t_grid	init;
	int		i;
	int		j;
	
	init.tab = (char **)malloc(sizeof(char *) * 6);
	if (!init.tab)
		exit(1);
	i = 0;
	while (i < 5)
	{
		init.tab[i] = (char *)malloc(sizeof(char) * 6);
		if (!init.tab[i])
			exit(1);
		j = 0;
		while (j < 5)
		{
			init.tab[i][j] = '_';
			j++;
		}
		init.tab[i][j] = 0;
		i++;
	}
	init.tab[i] = 0;
	init.word = strdup(guess);
	if (!init.word)
		exit(1);
	return (init);
}
