#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret_value;
	size_t	counter;

	counter = ft_strlen(str);
	ret_value = malloc(counter + 1);
	if (!ret_value)
		return (NULL);
	counter = 0;
	while (str[counter] != '\0')
	{
		ret_value[counter] = str[counter];
		counter++;
	}
	ret_value[counter] = '\0';
	return (ret_value);
}
