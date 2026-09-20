#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ret_value;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	ret_value = malloc(nmemb * size);
	if (!ret_value)
		return (NULL);
	ft_bzero(ret_value, nmemb * size);
	return ((void *)ret_value);
}
