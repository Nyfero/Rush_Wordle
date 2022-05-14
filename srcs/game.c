#include "../inc/RushWordle.h"

int game(t_grid grid, char ** dict, t_word *index)
{
	char	*input;
	int		nb_try;
	
	nb_try = 0;
	displayGrid(grid);
	while (nb_try < 6)
	{
		write(1, "input: ", 7);
		input = get_next_line(0);
		if (check_input(input, dict, index))
			;
		else
		{
			putInGrid(input, grid);
			displayGrid(grid);
			nb_try++;
			if (!strcmp(input, grid.word))
			{
				printf("\e[92mCongratulations you found the word %s in %d guesses !\n\e[39m", grid.word, nb_try);
				free(input);
				clean(grid);
				return (0);
			}
		}
		free(input);
	}
	printf("\e[91mYou loose !\nThe word was '%s'\n\e[39m", grid.word);
	clean(grid);
	return (0);
}

int	check_input(char *input, char **dict, t_word *index)
{
	int	i;

	if (!input)
	{
		printf("\e[91mNo Word !\e[39m\n");
		return (1);
	}
	if (strlen(input) != 5)
	{
		printf("\e[91mInvalid Word !\nThis word isn't strictly equal to five letters\e[39m\n");
		return (1);
	}
	i = -1;
	while (input[++i])
	{
		if (!isalpha(input[i]))
		{
			printf("\e[91mInvalid Word !\nA word contain only letters\e[39m\n");
			return (1);
		}
	}
	for (i = 0; input[i]; i++)
		input[i] = tolower(input[i]);
	if (check_existing_world(input, dict, index))
	{
		printf("\e[91mInvalid Word !\nThis word is not in the given words dictionnary\e[39m\n");
		return (1);
	}
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

int		check_existing_world(char *input, char **dict, t_word *index)
{
	int		i;
	int		j;
	char	tmp[6];

	for(int k = 0; input[k]; k++)
		tmp[k] = ft_tolower(input[k]);
	tmp[5] = 0;
	i = tmp[0] - 97;
	j = index[i].start;
	while (j < index[i].end)
	{
		if (!strcmp(tmp, dict[j]))
			return (0);
		j++;
	}
	return (1);
}
