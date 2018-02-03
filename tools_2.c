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

int					count_space(char *tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

static t_var			init_var(t_act *act)
{
	t_var	var;

	var.i = 1;
	var.tab_len = tablen(act);
	if (!(var.tmp = (char **)malloc(sizeof(char *) * (var.tab_len + 1))))
		return (var);
	return (var);
}

char				**morespaces(t_act *act)
{
	t_var	var;

	var = init_var(act);
	while (g_act.s_argv[var.i])
	{
		var.j = 0;
		var.size.spaces = lenmax_str(act) - ft_strlen(g_act.s_argv[var.i]);
		if (!(var.str = (char *)malloc(sizeof(char) * var.size.spaces)))
			return (NULL);
		while (var.j < (var.size.spaces))
		{
			var.str[var.j] = ' ';
			var.j++;
		}
		var.str[var.j] = '\0';
		var.tmp[var.i] = ft_strjoin(g_act.s_argv[var.i], var.str);
		free(var.str);
		var.i++;
	}
	var.tmp[var.i] = NULL;
	return (var.tmp);
}

int				wordbyline(t_size *size, t_act *act)
{
	int		sizemax;
	int		wordbyline;

	sizemax = lenmax_str(act);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
