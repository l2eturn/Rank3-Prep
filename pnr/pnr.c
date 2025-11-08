#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

void	sort_str(char *s)
{
	int i = 0, j;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				ft_swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

void	permute(char *s, int l, int r)
{
	int i;
	int used[256] = {0};

	if (l == r)
	{
		ft_putstr(s);
		return ;
	}
	for (i = l; i <= r; i++)
	{
		if (used[(unsigned char)s[i]])
			continue;
		used[(unsigned char)s[i]] = 1;

		ft_swap(&s[l], &s[i]);
		permute(s, l + 1, r);
		ft_swap(&s[l], &s[i]);
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	sort_str(av[1]);
	permute(av[1], 0, ft_strlen(av[1]) - 1);
}
