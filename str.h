#ifndef STR_H
# define STR_H

/*
 * Takes a string skips spaces and copies from first non space sign until next
 * whitespace outside of quotation marks and replaces variables if needed
 * return str with malloced copy ; if nothing there to copy retrun is null
 */
char	*str_copy(char *str);

#endif