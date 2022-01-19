# The name of the executable.
NAME = minishell

# The source files.
SRC = main.c command.c

# The header files.
HDR = command.h

# The compiled header files.
H_O = $(patsubst %.h,%.gch,$(HDR))

# The compiled source files.
OBJ = $(patsubst %.c,%.o,$(SRC))

# The flags to be used during compilation.
CFLAGS = -Wall -Werror -Wextra -g #-Ofast

# The includes for the project.
INC = -I. -I$(HOME)/.brew/opt/readline/include

# The flags to be used during linking.
LDFLAGS = -L$(HOME)/.brew/opt/readline/lib -lreadline


# Makes whatever is necessary.
all: $(NAME)

# Runs the norm checker on all registered files.
norm:
	norminette $(SRC) $(HDR) | grep :

# Runs the executable.
run: $(NAME)
	./$(NAME)

# Makes the bonus part of the project.
bonus: all

# Links the executable.
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

# Compiles each source file individually.
%.o: %.c $(H_O)
	$(CC) $(CFLAGS) -c -o $@ $<

# Compiles each header file individually.
%.gch: %.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Removes all temporary files.
clean:
	- $(RM) $(H_O) $(OBJ) *~
	- find . -name \*~ -print -delete

# Removes everything created by this makefile.
fclean: clean
	- $(RM) $(NAME)

# Removes all files created by this makefile and recompiles the project.
re: fclean all

# A list with all always dirty rules.
.PHONY: all clean flcean re bonus norm run
