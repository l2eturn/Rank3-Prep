void dfs(char *set, int start, char *buf, int buflen)
{
	print_subset(buf);

	int n = ft_strlen(set);
	for (int i = start; i < n ; i ++)
	{
		int len = ft_strlen(buf);
		if (len + 1 < buflen)
		{
			buf[len] = set[i];
			buf[len + 1] = '\0';
			dfs(set, start + 1, buf, buflen);
			buf[len] = '\0';
		}
	}
}
