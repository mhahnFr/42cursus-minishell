int	cnt_untl(char *string, char stopchar)
{
	int	i;

	i = 0;
	while (string[i] != stopchar && string[i] != '\0')
		i++;
	return (i);
}

int	cnt_args(char *string, char separator)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string[j] != '\0')
	{
		if ((j == 0 || string[j] == separator)
			&& string[j + 1] != '\0' && string[j + 1] != separator)
			i++;
		j++;
	}
}

char	*get_arg(char *string, char separator, int arg_num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (arg_num == 0)
	{
		while (string[i] == separator)
			i++;
		return (string[i]);
	}
	while (string[i] != '\0')
	{
		if ((i == 0 || string[i] == separator)
			&& string[i + 1] != '\0' && string[i + 1] != separator)
		{
			if (arg_num != 0)
				arg_num--;
			else
				return (string[i + 1]);
		}
		i++;
	}
	return (NULL);
}

void	parse(char *str, t_cmd *cmd, char **envp)
{
	int	i;

	i = cnt_args(str, ' ');
	
	cmd->infile
}


int	pipex_utils_cnt(char *str, char divider, int mode)
{
	int	i;
	int	j;

	i = 0;
	if (mode == 2)
		while (str[i] != divider && str[i] != '\0')
			i++;
	else if (mode == 1)
		while (str[i] == divider)
			i++;
	else
	{
		j = 0;
		while (str[j] != '\0')
		{
			if ((j == 0 || str[j] == divider)
				&& str[j + 1] != '\0' && str[j + 1] != divider)
				i++;
			j++;
		}
	}
	return (i);
}

char	*cmd_w_path(t_cmd *cmd, char **envp)
{
	int		len[2];
	char	*ret;

	len[0] = pipex_utils_cnt(*nargs[0], ' ', 2);
	len[1] = pipex_utils_cnt(envs, ':', 2);
	ret = malloc(sizeof(char) * (len[0] + len[1] + 2));
	if (ret == NULL)
		pipex_free(nargs, "malloc", 0);
	pipex_utils_combine(&ret, envs, *nargs[0], len);
	if (access(ret, X_OK))
	{
		free(ret);
		if (envs[len[1]] != '\0')
			ret = pipex_get_cmd(nargs, &envs[len[1]] + 1);
		else
			pipex_free(nargs, *nargs[0], 2);
	}
	return (ret);
}

void	execute(t_cmd *cmd, char **envp)
{
	execve(pipex_get_cmd(cmd.cmd[0], envp), cmd.cmd, envp);

}