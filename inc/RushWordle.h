#ifndef RUSHWORDLE_H
# define RUSHWORDLE_H

# define FILE_PATH "words.txt"

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "../libft/inc/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <errno.h>
# include <time.h>
# include <sys/random.h>

typedef struct s_word
{
	char	letter;
	int		start;
	int		end;
	int		current;
}	t_word;

typedef struct s_grid
{
	char	**tab;
	char	*word;
}	t_grid;

//	init.c
t_grid	initGridGame(char *guess);
void	init_word_index(t_word *word_index);
void	ft_update_word_index(t_word *word_index);
int		ft_fill_word_table(char **word_table, t_word *word_index);
char	**init_table(int word_count);
int		parse_word_file(t_word *word_index);

//	utils.c
int		ft_str_isalpha(char *str);
void	clean(t_grid grid);
void	ft_incr_word_index(t_word *word_index, char first_letter);
void	ft_print_word_table(char **word_table);
int		check_line(char *line);

//	game.c
int		game(t_grid disp, char ** dict, t_word *index);
int		check_input(char *input, char **dict, t_word *index);
void	putInGrid(char *input, t_grid grid);
int		check_existing_world(char *input, char **dict, t_word *index);

//	display.c
void	displayGameStart(void);
void	displayGrid(t_grid grid);
int		letterInWord(char c, char *tmp);

#endif
