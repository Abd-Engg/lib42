#include "libft.h"

static char	*copy(char *strjoin, char const *src)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = ft_strlen(strjoin);
	while (src[i] != '\0')
	{
		strjoin[start + i] = src[i];
		i++;
	}
	strjoin[start + i] = '\0';
	return (strjoin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_value;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	ret_value = malloc(size + 1);
	if (!ret_value)
		return (NULL);

	ret_value[0] = '\0';
	copy(ret_value, s1);
	copy(ret_value, s2);
	return (ret_value);
}
