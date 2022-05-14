#include "../inc/RushWordle.h"

int	main(void)
{
	t_grid	grid;
	t_word	word_index[26];
	char	**word_table;
	int		word_count;
	char	*guess;

	if ((word_count = parse_word_file(word_index)) == -1)
	{
		printf("File parsing error\n");
		return (1);
	}
	ft_update_word_index(word_index);
	word_table = init_table(word_count);
	if (ft_fill_word_table(word_table, word_index) == -1)
	{
		ft_free_ls(word_table);
		return (1);
	}
	srand(time(NULL));
	guess = strdup(word_table[(rand() % word_count)]);
	if (!guess)
	{
		ft_free_ls(word_table);
		return (1);
	}
	// ft_print_word_table(word_table);
	displayGameStart();
	grid = initGridGame(guess);
	game(grid, word_table, word_index);
	ft_free_ls(word_table);
	free(guess);
	return (0);
}
