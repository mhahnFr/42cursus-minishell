#ifndef SKIP_H
# define SKIP_H

/*
 * Checks if string has quotationmarks and moves over them
 * returns amount of chars needed to move to be on the next cgar that
 * is not inbetween quotationmarks
 */
int	skip_qtm_and_move(char *str);

#endif