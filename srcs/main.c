#include "../inc/RushWordle.h"

int	main(void)
{
	t_grid	grid;

	displayGameStart();
	grid = initGridGame("aahed");
	game(grid);
	return (0);
}
