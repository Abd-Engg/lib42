#include "libft.h"

static int	count_digits(long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			sign;
	int			number_index;
	char		*n_char;
	int			i;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	number_index = count_digits(nb);
	n_char = malloc(number_index + 1 + sign);
	if (!n_char)
		return (NULL);
	n_char[number_index + sign] = '\0';
	i = number_index + sign - 1;
	while (i >= 0)
	{
		n_char[i] = nb % 10 + '0';
		i--;
		nb /= 10;
	}
	if (sign)
		n_char[0] = '-';
	return (n_char);
}
