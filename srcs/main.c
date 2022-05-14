#include "../inc/RushWordle.h"

int	main(void)
{
	t_grid	grid;
	t_word  word_index[26];
	char **word_table;
	int		word_count;

	if ((word_count = parse_word_file(word_index) == -1))
	{
		printf("File parsing error\n");
		return -1;
	}
	ft_update_word_index(word_index);
	word_table = init_table(word_count);
	displayGameStart();
	grid = initGridGame("times");
	game(grid);
	return (0);
}
