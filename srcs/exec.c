#include "../inc/RushWordle.h"

int exec()
{
	char	*input;
	int		nb_try;
	
	nb_try = 0;
	while (nb_try < 5)
	{
		input = readline("input: ");
		if (check_input(input))
			;
		else
			nb_try++;
	}
	return (0);
}

int	check_input(char *input)
{
	int	i;

	if (strlen(input) != 5)
	{
		printf("\e[91mInvalid Word !\nEach word is strictly equal to five letters\n\e[39m");
		return (1);
	}
	i = -1;
	while (input[++i])
		if (!isalpha(input[i]))
			return (1);
	return (0);
}
