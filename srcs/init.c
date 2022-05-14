#include "../inc/RushWordle.h"

t_grid	initGridGame(char *guess)
{
	t_grid	init;
	int		i;
	int		j;
	
	init.tab = (char **)malloc(sizeof(char *) * 6);
	if (!init.tab)
		exit(1);
	i = 0;
	while (i < 5)
	{
		init.tab[i] = (char *)malloc(sizeof(char) * 6);
		if (!init.tab[i])
			exit(1);
		j = 0;
		while (j < 5)
		{
			init.tab[i][j] = '_';
			j++;
		}
		init.tab[i][j] = 0;
		i++;
	}
	init.tab[i] = 0;
	init.word = strdup(guess);
	if (!init.word)
		exit(1);
	return (init);
}

void	init_word_index(t_word *word_index)
{
	char a_to_z = 'a';
	for (int i = 0; i < 26; i++)
	{
		word_index[i].letter = a_to_z;
		word_index[i].start = 0;
		word_index[i].end = 0;
		word_index[i].current = 0;
		a_to_z += 1;
	}
}

void    ft_update_word_index(t_word *word_index)
{
	word_index[0].start = 0;
	word_index[0].end = word_index[0].end - 1;
	for (int i = 1; i < 26; i++)
	{
		word_index[i].start = word_index[i - 1].end + 1;
		word_index[i].end = word_index[i].start + word_index[i].end - 1;
	}
}

char	**init_table(int word_count)
{
	char	**word_table;

	word_table = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word_table == NULL)
		return (NULL);
	word_table[word_count] = NULL;
	for (int i = 0; i < word_count; i++)
	{
		word_table[i] = (char *)malloc(sizeof(char) * 6);
		if (word_table[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free(word_table[j]);
			free(word_table);
			return (NULL);
		}
		word_table[i][5] = 0;
	}
	return (word_table);
}

int		parse_word_file(t_word *word_index)
{
	int		word_count = 0;
	size_t	len = 0;
	char	*line = NULL;
	FILE	*fd = fopen("words.txt", "r");
	int ret;

	init_word_index(word_index);
	if (fd == NULL)
	{
		printf("Error : parse_file : open failed\n");
		return (-1);
	}
	while ((ret = getline(&line, &len, fd)) != -1)
	{
		if (check_line(line))
			return (-1);
		word_count += 1;
		ft_incr_word_index(word_index, line[0]);
	}
	free(line);
	if (ret == -1 && errno != 0)
	{
		printf("Getline : Errno : %s\n", strerror(errno));
		return (-1);
	}
	if (fclose(fd) != 0)
	{
		printf("Error : parse_file : close failed\n");
		return (-1);
	}
	return (word_count);
}
