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
}	t_world;

int		check_input(char *input);
int		exec();

void	displayGameStart(void);
#endif
