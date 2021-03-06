/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:45 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:02:46 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <unistd.h>

# include "token.h"

/*
 * Returns wether the given character is a whitespace.
 */
bool	utils_is_whitespace(const char c);

/*
 * Returns wether the given string consists only of whitespaces. Returns false
 * if no string is given.
 */
bool	utils_only_whitespace(const char *string);

/*
 * Frees all contents of the given string array. It has to be null terminated.
 * Does nothing if no array is given.
 */
void	utils_free_char_array(char **array);

/*
 * Frees token. Everything there has to be allocated with
 * malloc to avoid freeing unallocated memory.
 */
int		utils_free_token(t_token *token, int mode);

/*
 * Returns wether the given string represents a valid identifier. That is, it
 * only contains alphanumeric characters or underscores and does not start with
 * a digit. If no string is given, false is returned.
 */
bool	utils_is_identifier(char *string);

/*
 * Returns wether the given string represents a valid identifier for the given
 * length. That is, it only contains alphanumeric characters or underscores and
 * does not start with a digit. If no string is given, false is returned.
 */
bool	utils_is_identifier_length(char *string, size_t length);

/*
 * Compares the two given strings literally. If one of them is null, false is
 * returned, if both are null, true is returned. Otherwise, they are compared.
 */
bool	string_equals(const char *self, const char *other);

/*
 * Compares the two given strings literally. If one of them is null, false is
 * returned, if both are null, true is returned. Otherwise, true is returned if
 * the first string starts with the second one. If the second string is longer
 * than the first, the string is considered to not start with the second one.
 * If the two strings contain exactly the same characters, true is returned.
 */
bool	string_starts_with(const char *self, const char *start);

/*
 * Returns the value of the given variable stored in the environment. If the
 * given variable is not found in the environment, an empty string is returned.
 */
char	*ft_getenv(const char *string, char **env);

/*
 * Returns the corresponding entry in the given environment of the given
 * variable. If no entry is found for the given variable, null is returned.
 */
char	*ft_getenv_entry(const char *var, char **env);

/*
 * Returns wether the given environment contains the given variable.
 */
bool	ft_hasenvvar(const char *var, char **env);

/*
 * Returns wether the given string starts with the other given string. If one
 * of them is null, false is returned. Otherwise, they are compared. The given
 * string has to have the given character after the length of the beginning
 * string.
 */
bool	string_starts_with_ec(
			const char *self, const char *start, const char end);

/*
 * Calculates the count of elements in the given environment. Given null, zero
 * is returned.
 */
size_t	get_env_size(const char **env);

/*
 * Allocates a new char array and copys the contents of the environment.
 * Returns either the newly allocated array or null if the allocation failed.
 */
char	**copy_env(void);

#endif
