#include "../inc/RushWordle.h"

int	main(void)
{
	t_grid	grid;

	displayGameStart();
	grid = initGridGame("times");
	game(grid);
	return (0);
}
