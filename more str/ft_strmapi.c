#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_value;
	int		i;

	ret_value = malloc(ft_strlen(s) + 1);
	if (!ret_value)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret_value[i] = f(i, s[i]);
		i++;
	}
	ret_value[i] = '\0';
	return (ret_value);
}
