#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
//		printf("%zu\n",dest_len);

	src_len = ft_strlen(src);
	//		printf("%zu\n",src_len);

	if (size <= dest_len)
		return (size + src_len);
		
	ft_strlcpy(&dest[dest_len], src, size - dest_len);
	return (dest_len + src_len);
}
