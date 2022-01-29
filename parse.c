#include <unistd.h>
#include <stdlib.h>

#include "token.h"
#include "str.h"
#include "libft.h"

// void	parse_infile(char *file)
// {

// }

int	parse_run(char *str, char *env, char **envp)
{
	int		i;
	char	*cmd;
	char	**c_args;
	int		tmp;
	pid_t	child;

	i = 0;
	if (env == NULL)
		env = getenv("PATH");
	while (env[i] != '\0' && env[i] != ':')
		i++;
	if (i == 0)
		return (-1);
	tmp = i;
	cmd = str_copy(str, i + 1);
	cmd[i] = '/';
	while (i > 0)
	{
		i--;
		cmd[i] = env[i];
	}
	if (0 != access(cmd, X_OK))
	{
		free(cmd);
		return(parse_run(str, &env[tmp + 1], envp));
	}
	c_args = malloc(sizeof(char *) * 2);
		if (c_args == NULL)
			exit (-1);
	c_args[1] = NULL;
	c_args[0] = str_copy(str, 0);
	child = fork();
	if (0 != child)
			execve(cmd, c_args, envp);
	free(cmd);
	free(c_args);
	return(0);
}

void	parse_func(t_token *token, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while(i != token->strlen)
	{
		if ((token->str)[i] == '<' && (token->str)[i + 1] == '<')
		{
			while ((token->str)[i + 2] == ' ')
				i++;
			if (str_copy(&(token->str)[i + 2], 0) != NULL)
			{
				j = ft_strlen(str_copy(&(token->str)[i + 2], 0));
				write(1, str_copy(&(token->str)[i + 2], j), 0);
			}
			else
				write(1, "(null)", 6);
		}
		// if ((token->str)[i] == '<' && (token->str)[i + 1] == '<')
		// 	i = parse_here_document(&(token->str)[i + 2]);
		// else if ((token->str)[i] == '<')
		// 	i = parse_infile(&(token->str)[i + 1]);
		// else if ((token->str)[i] == '>' && (token->str)[i + 1] == '>')
		// 	i = parse_append_outfile(&(token->str)[i + 2]);
		// else if ((token->str)[i] == '>')
		// 	i = parse_outfile(&(token->str)[i + 2]);
		// else 
		if ((token->str)[i] != ' ')
		{
			i = parse_run(token->str, NULL, envp);
			i = token->strlen;
			break ;
		}
		i++;
	}
}