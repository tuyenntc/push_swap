#include "push_swap.h"
#include <stdio.h>

/**********************************************************************************************************************
* how many words are there in the input string?
* allocate memory for the required space + null terminator
* copy the substring/ each word inside the whole string
* split into and array of string to hold each single word
*
**********************************************************************************************************************/


//"hi how are you"==> hi / how / are / you /0
static int	count_word(char *s, char c)
{
	int		i;
	bool	inside_word;

	i = 0;
	inside_word = false;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++i;
				inside_word = true;
			}
			++s;
		}
		inside_word = false;
	}
	return (i);
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


static char	*get_substr(char *s, char c)
{
	char	*substr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		++len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[i];
		++i;
	}
	substr[i] = '\0';
	while (*s && *s != c)
		++s;
	while (*s && *s == c)
		++s;
	return (substr);
}

/*
int main(void)
{
	char	s[] = "this is a test string";
	char	c = ' ';
	char	*word;
	while ((word = get_substr(s, c)) != NULL)
	{
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
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		return (NULL);
	while (*input && i < size)
	{
		position = 0;
		while (*input && *input == c)
			++input;
		if (!*input)
			break;
		result[i] = get_substr(input, c);
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
	char	input[] = "this,is,a,test,string";
	char	c = ',';
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


