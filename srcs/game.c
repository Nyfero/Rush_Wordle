#include "../inc/RushWordle.h"

int game(t_grid grid/*, char ** dict, t_word index*/)
{
	char	input[6];
	int		nb_try;
	FILE	*fd;
	
	nb_try = 0;
	fd = fopen(0, "r");
	displayGrid(grid);
	while (nb_try < 5)
	{
		write(1, "0\n", 2);
		fgets(input, sizeof(input) - 1, fd);
		write(1, "0\n", 2);
		// input = readline("input: ");
		if (check_input(input/*, dict, index*/))
			;
		else
		{
			putInGrid(input, grid);
			displayGrid(grid);
			nb_try++;
			if (!strcmp(input, grid.word))
			{
				printf("Congratulations you found the word %s in %d guesses !\n", grid.word, nb_try);
				// free(input);
				break;
			}
		}
		// free(input);
	}
	clean(grid/*, index*/);
	return (0);
}

int	check_input(char *input/*, char **dict, t_word index*/)
{
	int	i;

	if (!input)	//ctl + D
	{
		printf("\e[91mNo Word !\e[39m\n");
		return (1);
	}
	if (strlen(input) != 5)	//size < 5
	{
		printf("\e[91mInvalid Word !\nThis word isn't strictly equal to five letters\e[39m\n");
		return (1);
	}
	i = -1;
	while (input[++i])	//number in the word
	{		
		if (!isalpha(input[i]))
		{
			printf("\e[91mInvalid Word !\nA word doesn't contain a number\e[39m\n");
			return (1);
		}
	}
	/*if (check_existing_world(input, dict, index))	//existing word
	{
		printf("\e[91mInvalid Word !\nThis word is not in the given words dictionnary\e[39m\n");
		return (1);	
	}*/
	return (0);
}

void	putInGrid(char *input, t_grid grid)
{
	int	i;
	int	j;
	
	i = -1;
	while (grid.tab[++i])
	{
		if (grid.tab[i][0] == '_')
		{
			j = -1;
			while (grid.tab[i][++j])
				grid.tab[i][j] = input[j];
			return ;
		}
	}
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
