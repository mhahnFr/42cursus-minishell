#include "libft/libft.h"

void	copy_cnt_var(char *src, int *src_cnt, int *dst_cnt)
{
	int	i;

	i = 1;
	while ((src[i] >= 'a' && src[i] <= 'z') || (src[i] >= 'A' && src[i] <= 'Z')
		|| (src[i] >= '0' && src[i] <= '9') || src[i] >= '_' )
		i++;
	if (i == 1)
		return ;
	// TODO dst_cnt adjsutment;
	*src_cnt = *src_cnt + i;
	*dst_cnt = *dst_cnt;
}

void	copy_arg(char *src, char *dst)
{
	int		src_cnt;
	size_t	dst_cnt;

	src_cnt = 0;
	dst_cnt = 0;
	while (src[src_cnt] != ' ' && src[src_cnt] != '\0')
	{
		if (src[src_cnt] == '\'')
		{
			while (src[src_cnt] != '\'')
			{
				src_cnt++;
				dst_cnt++;
			}
			dst_cnt = dst_cnt - 2;
		}
		else if (src[src_cnt] == '\"')
		{
			while (src[src_cnt] != '\"')
			{
				if (src[src_cnt] == '$')
					copy_cnt_var(src[src_cnt], &src_cnt, &dst_cnt);
				src_cnt++;
				dst_cnt++;
			}
			dst_cnt = dst_cnt - 2;
		}
		else if (src[src_cnt] == '$')
			copy_cnt_var(src[src_cnt], &src_cnt, &dst_cnt);
		src_cnt++;
		dst_cnt++;
	}
	dst = malloc(sizeof(char) * dst_cnt + 1);
	if (ft_strlcpy(dst, src, dst_cnt) != dst_cnt)
		return ; //TODO free
}
