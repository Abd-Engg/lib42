#include "libft.h"

static int	count_words(char *string, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (string[i])
	{
		while (string[i] && string[i] == c)
			i++;
		if (string[i])
		{
			counter++;
			while (string[i] && string[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	*cut(char *string, int start, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = string[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char *string, char c)
{
	char	**words;
	int		i;
	int		j;
	int		start;
	int		len;

	words = malloc(sizeof(char *) * (count_words(string, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i] && string[i] == c)
			i++;
		start = i;
		while (string[i] && string[i] != c)
			i++;
		len = i - start;
		words[j] = cut(string, start, len);
		if (!words[j])
		{
			free_words(words);
			return (NULL);
		}
		j++;
	}
	words[j] = NULL;
	return (words);
}
