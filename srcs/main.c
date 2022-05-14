#include "../inc/RushWordle.h"

int     parse_word_file(t_word *word_index)
{
    init_word_index(word_index);
    int word_count = 0;
    size_t len = 0;
    char *line = NULL;
    //Ouvrir le fichier
    FILE *fd = fopen("words.txt", "r");
    if (fd == NULL)
    {
        printf("Error : parse_file : open failed\n");
        return -1;
    }
    int ret;
    while ((ret = getline(&line, &len, fd)) != -1)
    {
        if (strlen(line) == 6)
        {
            if (line[5] != '\n')
            {
                free(line);
                return (-1);
            }
        }
        else
        {
            if (strlen(line) != 5 || line[5] != '\0')
            {
                free(line);
                return (-1);
            }
        }
        if (ft_str_isalpha(line) == -1)
        {
            free(line);
            return -1;
        }
        word_count += 1;
        ft_incr_word_index(word_index, line[0]);
        //free(line) avant de relancer ?
        //line = NULL
    }
    if (ret == -1 && errno != 0)
    {
        printf("Getline : Errno : %s\n", strerror(errno));
        free(line);
        return -1;
    }
	printf("Word count = %d\n", word_count);
	printf("full file read\n");
	if (fclose(fd) != 0)
	{
		printf("Error : parse_file : close failed\n");
		return -1;
	}
	return word_count;
}

int	main(void)
{
	t_grid	grid;
	t_word  word_index[26];
	char **word_table;
	(void)word_table;
	int word_count = parse_word_file(word_index);
	if (word_count == -1)
	{
		printf("File parsing error\n");
		return -1;
	}
	/*
	//malloc char **word_table(sizeof(word_count))
	if (word_table == NULL)
	{
	printf("Wordtable = NULL");
	return (-1);
	}
	*/
	displayGameStart();
	grid = initGridGame("times");
	game(grid);
	return (0);
}
