void	input_here_document(char *str)
{
	while (*str = ' ')
		str++;
}

void	input_file(char *str)
{
	while (*str = ' ')
		str++;
}

void	output_append(char *str)
{
	while (*str = ' ')
		str++;
}

void	output_file(char *str)
{
	while (*str = ' ')
		str++;
}

void	tokenize(char *str, int strlen)
{
	while(strlen != 0)
	{
		if (str[0] == '<' && str[1] == '<')
			input_here_document(&str[2]);
		else if (str[0] == '<')
			input_file(&str[1]);
		else if (str[0] == '>' && str[1] == '>')
			output_append(&str[2]);
		else if (str[0] == '>')
			output_file(&str[1]);
		else if (str[0] != ' ')
			return ;
		str++;
		strlen--;
	}
}

