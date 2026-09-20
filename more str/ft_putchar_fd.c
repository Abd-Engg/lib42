#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	char	ch;

	ch = (char)c;
	write(fd, &ch, 1);
}
