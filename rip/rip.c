#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int	is_valid(char *s)
{
	int i = 0;
	int count = 0;

	while (s[i])
	{
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
		{
			if (count == 0)
				return (0);
			count--;
		}
		i++;
	}
	return (count == 0);
}

/*
** remove_char: คืนค่า string ใหม่ที่ลบอักขระ index i ออกหนึ่งตัว
*/
char	*remove_char(char *s, int i)
{
	int len = ft_strlen(s);
	char *res = malloc(len);
	int j = 0, k = 0;

	if (!res)
		return (NULL);
	while (s[j])
	{
		if (j != i)
			res[k++] = s[j];
		j++;
	}
	res[k] = '\0';
	return (res);
}

/*
** backtrack:
**  - s: string ปัจจุบัน
**  - start: index ที่เริ่มลบ
**  - rem: จำนวนวงเล็บที่ต้องลบออกให้เหลือ valid
**  - seen: เก็บผลลัพธ์ที่เคยพิมพ์แล้ว (กันซ้ำ)
*/
void	backtrack(char *s, int start, int rem)
{
	if (rem == 0)
	{
		if (is_valid(s))
			ft_putstr(s);
		return ;
	}
	int len = ft_strlen(s);
	for (int i = start; i < len; i++)
	{
		// ข้ามตัวซ้ำกัน เช่น ((()))
		if (i > start && s[i] == s[i - 1])
			continue;
		if (s[i] == '(' || s[i] == ')')
		{
			char *next = remove_char(s, i);
			backtrack(next, i, rem - 1);
			free(next);
		}
	}
}

/*
** count_invalid:
**  - หาว่าต้องลบวงเล็บกี่ตัวถึงจะ valid
*/
int	count_invalid(char *s)
{
	int open = 0, close = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open == 0)
				close++;
			else
				open--;
		}
	}
	return (open + close);
}

/*
** main: ใช้งานแบบ
**   ./a.out "()())()"
*/
int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	int rem = count_invalid(av[1]);
	backtrack(av[1], 0, rem);
	return (0);
}
