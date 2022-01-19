# The name of the executable.
NAME = minishell

# The source files.
SRC = ./main.c ./command.c

# The header files.
HDR = ./command.h ./parser.h

# The path to the libft.
LFT_P = ./libft

LFT_D = $(LFT_P)/libft.a

# The compiled header files.
H_O = $(patsubst %.h,%.gch,$(HDR))

# The compiled source files.
OBJ = $(patsubst %.c,%.o,$(SRC))

# The flags to be used during compilation.
CFLAGS = -Wall -Werror -Wextra $(INC) -g #-Ofast

# The includes for the project.
INC = -I. -I$(HOME)/.brew/opt/readline/include -I$(LFT_P)

# The flags to be used during linking.
LDFLAGS = -L$(HOME)/.brew/opt/readline/lib -lreadline -L$(LFT_P) -lft


# Makes whatever is necessary.
all: $(NAME)

# Runs the norm checker on all registered files.
norm:
	norminette $(SRC) $(HDR) | grep :

# Runs the executable.
run: $(NAME)
	./$(NAME)

# Calls the makefile of the libft.
$(LFT_D):
	$(MAKE) -C $(LFT_P)

# Makes the bonus part of the project.
bonus: all

# Links the executable.
$(NAME): $(OBJ) $(LFT_D)
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
	- $(MAKE) -C $(LFT_P) clean
	- find . -name \*~ -print -delete

# Removes everything created by this makefile.
fclean: clean
	- $(RM) $(NAME)
	- $(MAKE) -C $(LFT_P) fclean

# Removes all files created by this makefile and recompiles the project.
re: fclean all

# A list with all always dirty rules.
.PHONY: all clean flcean re bonus norm run
