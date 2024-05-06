#include "push_swap.h"
#include <stdio.h>

/**********************************************************************************************************************
* how many words are there in the input string?
* allocate memory for the required space + null terminator
* copy the substring/ each word inside the whole string
* split into an array of string to hold each single word
*
**********************************************************************************************************************/


//"hi how are you"==> hi / how / are / you /0

static int	count_word(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

/*
int main(void)
{
	char	s[] = "hi how are you";
	char	c = ' ';
	int	word_count = count_word(s, c);
	printf("number of words in the test string: %d\n", word_count);
	return (0);
}
*/

static char *get_substr(char *s, char c, int *cursor)
{
	int	len;
	int i;
	char *result;

	len = 0;
	i = 0;
	result = NULL;
	while (s[*cursor] == c && s[*cursor] != '\0')
		++(*cursor);
	while ((s[*cursor + len] != c) && (s[*cursor + len] != '\0'))
		++len;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
		result[i++] = s[(*cursor)++];
	result[i] = '\0';
	return (result);
}

/*
int main(void)
{
	char	s[] = "this is a test string";
	char	c = ' ';
	int		cursor = 0;
	char	*word;
	while (s[cursor] != '\0')
	{
		word = get_substr(s, c, &cursor);
		if (word == NULL)
			break;
		printf("sub string: %s\n", word);
		free(word);
	}
	return (0);
}

*/
char	**split(char *input, char c)
{
	int		size;
	char	**result;
	int		i;
	int		position;
	
	position = 0;
	i = 0;
	size = count_word(input, c);
	if (size == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (size + 2));
	if (result == NULL)
		return (NULL);
	while (*input && i < size)
	{
		position = 0;
		while (*input && *input == c)
			++input;
		if (!*input)
			break;
		result[i] = get_substr(input, c, &position);
		if (result[i] == NULL)
		{
			while (i-- >0)
				free(result[i]);
			free(result);
			return (NULL);
		}
		while (*input && *input != c)
			++input;
		++i;
	}
	result[i] = NULL;
	return (result);
}



/*
int main(void)
{
	char	input[] = "12 6 33";
	char	c = ' ';
	int		i = 0;
	char	**word_arr = split(input, c);
	if (word_arr)
	{
		while (word_arr[i])
		{
			printf("word %d: %s\n", i + 1, word_arr[i]);
			free(word_arr[i]);
			++i;
		}
		free(word_arr);
	}
	else
		printf("errors spliting text string\n");
	return (0);
}
*/
