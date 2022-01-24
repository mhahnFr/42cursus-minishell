#ifndef TOKEN_TYPE_H
# define TOKEN_TYPE_H

/*
 * An enumeration with the possible types a token can have.
 */
enum e_type {
	UNDEFINED,
	OPERATOR,
	COMMAND,
	IN_REDIRECTION,
	OUT_REDIRECTION
};

#endif
