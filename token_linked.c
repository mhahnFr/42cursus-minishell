#include <stddef.h>

#include "token.h"

void	token_append(struct s_token **self, struct s_token *appendix)
{
	if (*self == NULL)
	{
		appendix->next = NULL;
		appendix->previous = appendix;
		*self = appendix;
		return ;
	}
	(*self)->previous->next = appendix;
	appendix->next = NULL;
	appendix->previous = (*self)->previous;
	(*self)->previous = appendix;
}
