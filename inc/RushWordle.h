#ifndef RUSHWORDLE_H
# define RUSHWORDLE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>

typedef struct s_word
{
	char	letter;
	int		start;
	int		end;
}	t_word;

typedef struct s_grid
{
	char	**tab;
	char	*word;
}	t_grid;

//	init.c
t_grid	initGridGame(char *guess);

//	game.c
int		game(t_grid disp/*, char ** dict, t_word index*/);
int		check_input(char *input/*, char **dict, t_word index*/);
void	putInGrid(char *input, t_grid grid);

//	display.c
void	displayGameStart(void);
void	displayGrid(t_grid grid);
#endif
