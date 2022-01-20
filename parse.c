#include <unistd.h>
#include <stdlib.h>

#include "copy.h"
#include "command.h"

void	parse_check_sequence(char *string)
{
	int		i;
	char	cha;

	while (string[i] != '\0')
	{
		cha = string[i];
		if (cha == '\'' || cha == '\"')
		{
			while (string[i] != cha)
			{
				if (string[i] == '\0')
				{
					write(2, "Parse: Parse Error", 18);
					exit(-1);
				}
				i++;
			}
		}
		i++;
	}
}

int	parse_cnt_args(char *string)
{
	int		cnt;
	int		i;
	char	cha;

	cnt = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if ((i == 0 || string[i] == ' ')
			&& string[i + 1] != '\0' && string[i + 1] != ' ')
			cnt++;
		cha = string[i];
		if (cha == '\'' || cha == "\"")
			while (string[i] != cha)
				i++;
		i++;
	}
	return (cnt);
}

void	parse_block(char *string)
{
	int		arg_cnt;
	char	**args;
	int		i;
	int		j;

	arg_cnt = parse_cnt_args(string);
	args = malloc(sizeof(char *) * (arg_cnt + 1));
	if (args == NULL)
		free_cmd();
	j = 0;
	while (i != arg_cnt)
	{
		j = j + copy_arg(&string[j], args[i]);
		args[i + 1] = NULL;
	}
}

void	parse(char *string)
{
	parse_check_sequence(string);
	parse_block(string);
}
