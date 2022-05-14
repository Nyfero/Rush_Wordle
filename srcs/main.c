#include "../inc/RushWordle.h"

void    ft_incr_word_index(t_word *word_index, char first_letter)
{
    //Verifer toupper ?? 
    int letter_index = first_letter - 97;
    word_index[letter_index].end += 1;
}

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

void    ft_update_word_index(t_word *word_index)
{
    printf("\t*********************************\n");
    word_index[0].start = 0;
    word_index[0].end = word_index[0].end - 1;
    for (int i = 1; i < 26; i++)
    {
        word_index[i].start = word_index[i - 1].end + 1;
        word_index[i].end = word_index[i].start + word_index[i].end - 1;
    }

}

int	main(void)
{
	t_grid	grid;
	t_word  word_index[26];
	char **word_table;
	if ((word_count = parse_word_file(word_index) == -1))
	{
        printf("File parsing error\n");
		return -1;
	}
    ft_update_word_index(word_index);
	word_table = (char **)malloc(sizeof(char*) * (word_count + 1));
	if (word_table == NULL)
	    return (-1);
    word_table[word_count] = NULL;
    for (int i = 0; i < word_count; i++)
    {
        word_table[i] = (char*)malloc(sizeof(char) * 6);
        if (word_table[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(word_table[j];
            free(word_table);
        }
        word_table[5] = '\0';
    }
	displayGameStart();
	grid = initGridGame("times");
	game(grid);
	return (0);
}
