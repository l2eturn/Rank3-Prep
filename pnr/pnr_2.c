#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len ++;
	return len;
}

void ft_putstr(char *str)
{
	int len = 0;
	while (str[len])
		write(1,&str[len++],1);
	write(1,"\n",1);
}

void ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void pnr(char *str, int l, int r)
{
	int i;
	int used[256] = {0};

	if (l == r)
	{
		ft_putstr(str);
		return ;
	}
	for (i = l; i <= r; i ++)
	{
		if (used[(unsigned char)str[i]])
			continue;
		used[(unsigned char)str[i]] = 1;
		ft_swap(&str[l],&str[i]);
		pnr(str,l+1,r);
		ft_swap(&str[l],&str[i]);
	}
}

void sort_str(char *str)
{
	int i = 0,j;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i],&str[j]);
			j ++;
		}
		i ++;
	}
}

int main(int ac,char **av)
{
	if (ac != 2)
		return (write(1,"\n",1),0);
	sort_str(av[1]);
	pnr(av[1], 0, ft_strlen(av[1]) - 1);;
}
