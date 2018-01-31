#include	"ft_select.h"

int					tablen(char **argv)
{
	int		i;

	i = 0;
	if (!(argv))
		return (0);
	while (argv[i])
		i++;
	return (i);
}

char				**morespaces(char **argv)
{
	char	**tmp;
	char	*str;
	int		tab_len;
	t_size	size;
	int		i;
	int		j;

	i = 1;
	tab_len = tablen(argv);
	if (!(tmp = (char **)malloc(sizeof(char *) * (tab_len + 1))))
		return (NULL);
	while (argv[i])
	{
		j = 0;
		size.spaces = lenmax_str(argv) - ft_strlen(argv[i]);
		if (!(str = (char *)malloc(sizeof(char) * size.spaces)))
			return (NULL);
		while (j < (size.spaces))
		{
			str[j] = ' ';
			j++;
		}
		str[j] = '\0';
		tmp[i] = ft_strjoin(argv[i], str);
		free(str);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int				wordbyline(t_size *size, char **argv)
{
	int		sizemax;
	int		wordbyline;

	sizemax = lenmax_str(argv);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
