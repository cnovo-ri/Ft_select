#include	"ft_select.h"

int					tablen(t_act *act)
{
	int		i;

	i = 0;
	if (!(g_act.s_argv))
		return (0);
	while (g_act.s_argv[i])
		i++;
	return (i);
}

char				**morespaces(t_act *act)
{
	char	**tmp;
	char	*str;
	int		tab_len;
	t_size	size;
	int		i;
	int		j;

	i = 1;
	tab_len = tablen(act);
	if (!(tmp = (char **)malloc(sizeof(char *) * (tab_len + 1))))
		return (NULL);
	while (g_act.s_argv[i])
	{
		j = 0;
		size.spaces = lenmax_str(act) - ft_strlen(g_act.s_argv[i]);
		if (!(str = (char *)malloc(sizeof(char) * size.spaces)))
			return (NULL);
		while (j < (size.spaces))
		{
			str[j] = ' ';
			j++;
		}
		str[j] = '\0';
		tmp[i] = ft_strjoin(g_act.s_argv[i], str);
		free(str);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int				wordbyline(t_size *size, t_act *act)
{
	int		sizemax;
	int		wordbyline;

	sizemax = lenmax_str(act);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
