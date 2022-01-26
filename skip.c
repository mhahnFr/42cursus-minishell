int	skip_qtm_and_move(char *str)
{
	int		i;

	i = 1;
	if (str[0] == '"' || str[0] == '\'')
		while (str[i] != str[0])
			i++;
	return (i);
}
