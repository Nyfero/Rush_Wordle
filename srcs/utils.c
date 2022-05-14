#include "../inc/RushWordle.h"

int		ft_str_isalpha(char *str)
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

void	ft_incr_word_index(t_word *word_index, char first_letter)
{
	int	letter_index = first_letter - 97;
	word_index[letter_index].end += 1;
}

int		check_line(char *line)
{
	if (strlen(line) == 6)
	{
		if (line[5] != '\n')
		{
			free(line);
			return (1);
		}
	}
	else
	{
		if (strlen(line) != 5 || line[5] != '\0')
		{
			free(line);
			return (1);
		}
	}
	if (ft_str_isalpha(line) == -1)
	{
		free(line);
		return (1);
	}
	return (0);
}
