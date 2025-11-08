#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	match_here(char *buf, char *pat)
{
	int i = 0;
	while (pat[i] && buf[i])
	{
		if (buf[i] != pat[i])
			return (0);
		i++;
	}
	return (pat[i] == '\0');
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	char buf[9999];
	int bytes;
	char *pat = argv[1];
	int i;
	int len = ft_strlen(pat);

	while ((bytes = read(0, buf, 9999)) > 0)
	{
		i = 0;
		while (i < bytes)
		{
			if (match_here(&buf[i], pat))
			{
				for (int j = 0; j < len; j++)
					write(1, "*", 1);
				i += len;
			}
			else
				write(1, &buf[i++], 1);
		}
	}
	return (0);
}
