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

void	init_word_index(t_word *word_index)
{
	char a_to_z = 'a';
	for (int i = 0; i < 26; i++)
	{
		word_index[i].letter = a_to_z;
		word_index[i].start = 0;
		word_index[i].end = 0;
		word_index[i].current = 0;
		a_to_z += 1;
	}
}
