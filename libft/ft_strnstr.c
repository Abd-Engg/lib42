#include "libft.h"
static int check(const char *s1,const char *s2,size_t n)
{
	size_t i;

	i = 0;
	while (s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		 i++;
	}
	if (s2[i] != '\0')
		return (0);
	
	return (1);
	
}
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);

	while (haystack[i] != '\0' && i < len)
	{
		if (check(&haystack[i],&needle[0],len - i))
		{
			return ((char *)&haystack[i]);
		}		
		i++;
	}
	return (NULL);
}