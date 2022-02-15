# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 20:04:10 by mhahn             #+#    #+#              #
#    Updated: 2022/02/15 20:04:13 by mhahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the library to create.
NAME		=	libgnl.a

# The source files needed for the library.
SRC			=	get_next_line.c \
				get_next_line_utils.c

# The flags to compile the files with.
CFLAGS		=	-Wall -Werror -Wextra -Ofast

# A macro to get the object files for the corresponding source files.
OBJ			=	$(patsubst %.c,%.o,$(SRC))

# The buffer size to be used by the get_next_line function.
BUFFER_SIZE	=	64

# Compiles the whole library.
.phony: all
all: $(NAME)

# Creates the library.
$(NAME): $(OBJ)
	$(AR) -rs $(NAME) $(OBJ)

# Compiles each source file individually.
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -D BUFFER_SIZE=$(BUFFER_SIZE)

# Removes all object files.
.phony: clean
clean:
	- $(RM) $(OBJ)

# Removes all files created by this makefile.
.phony: fclean
fclean: clean
	- $(RM) $(NAME)

# Removes everything created by this makefile and recompiles the library.
.phony: re
re: fclean all
