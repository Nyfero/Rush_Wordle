#include "../inc/RushWordle.h"

void    ft_incr_word_index(t_word *word_index, char first_letter)
{

<<<<<<< HEAD
int ft_str_isalpha(char *str)
{
    for (int i = 0; i < 5; i++)
    {
        if (isalpha(str[i]) == 0)
            return (-1);
    }
    return 0;
}

void    ft_incr_word_index(t_word *word_index, char first_letter)
{
    //solution rapide : 
    /*
        char letter_index = 72 - first_letter
        word_index[letter_index].end += 1
    */
    //solution sure
    for (int i = 0; i < 26; i++)
    {
        if (word_index[i].letter == first_letter)
        {
            word_index[i].end += 1;
            return;
        }
    }
=======
	int letter_index = first_letter - 72;
	word_index[letter_index].end += 1;

	// for (int i = 0; i < 26; i++)
	// {
	// 	if (word_index[i].letter == first_letter)
	// 	{
	// 		word_index[i].end += 1;
	// 		return;
	// 	}
	// }

>>>>>>> f7dc4ea869c28a6454d6389500a8e9b3511d102c
}

int     parse_word_file(t_word *word_index)
{
<<<<<<< HEAD
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
    /*
    //Fin de ficher lecture ok
    printf("A -- line = %s | len = %lu\n", line, strlen(line));
    if (strlen(line) != 5 || strlen(line) != 0)
    {
        printf("B -- line = %s | len = %lu\n", line, strlen(line));
        if (line != NULL)
            free(line);
        return (-1);
    }
    if (strlen(line) == 5)
    {
        if (line[5] != '\0' || ft_str_isalpha(line) == -1)
        {
            printf("C -- line = %s | len = %lu\n", line, strlen(line));
            free(line);
            return (-1);
        }
    }
=======
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
	//Lire chaque ligne
	//incr word_index a element count a l'index de la lettre
	int ret;
	while ((ret = getline(&line, &len, fd)) != -1)
	{
		//Verif :
		// len == 5
		// isalpha only
		if (strlen(line) == 6)
		{
			if (line[5] != '\n')
			{
				printf("lol\n");
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
			printf("is alpha pbm\n");
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
	/*
	//Fin de ficher lecture ok
	printf("A -- line = %s | len = %lu\n", line, strlen(line));
	if (strlen(line) != 5 || strlen(line) != 0)
	{
	printf("B -- line = %s | len = %lu\n", line, strlen(line));
	if (line != NULL)
	free(line);
	return (-1);
	}
	if (strlen(line) == 5)
	{
	if (line[5] != '\0' || ft_str_isalpha(line) == -1)
	{
	printf("C -- line = %s | len = %lu\n", line, strlen(line));
	free(line);
	return (-1);
	}
	}
>>>>>>> f7dc4ea869c28a6454d6389500a8e9b3511d102c
*/
	printf("full file read\n");
	if (fclose(fd) != 0)
	{
		printf("Error : parse_file : close failed\n");
		return -1;
	}
	//Close file
	//Set up les range start et end dans wordindex
	//malloc le double tableau
	return 0;

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
