#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_value;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ret_value = malloc(len + 1);
	if (!ret_value)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret_value[i] = s[start + i];
		i++;
	}
	ret_value[i] = '\0';
	return (ret_value);
}
