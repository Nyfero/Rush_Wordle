#include "../inc/RushWordle.h"

int game(t_grid grid/*, char ** dict, t_word index*/)
{
	char	*input;
	int		nb_try;
	
	nb_try = 0;
	displayGrid(grid);
	while (nb_try < 5)
	{
		input = readline("input: ");
		if (check_input(input/*, dict, index*/))
			;
		else
		{
			putInGrid(input, grid);
			displayGrid(grid);
			nb_try++;
		}
	}
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
