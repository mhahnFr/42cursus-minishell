# The name of the executable.
NAME = minishell

# The source files.
SRC = main.c command.c signals.c signals_execution.c str.c parse.c \
	  signals_default.c syntax.c utils.c tokenizer.c token.c check.c \
	  pipe.c skip.c exec.c file.c

# The header files.
HDR = command.h signals.h syntax.h utils.h token.h exec.h file.h \
	  token_type.h tokenizer.h check.h pipe.h skip.h str.h parse.h

# The path to the libft.
LFT_P = ./libft

# The full path to the libft.
LFT_D = $(LFT_P)/libft.a

# the path to the object files.
O_P = ./bin

# The compiled source files.
OBJ = $(addprefix $(O_P)/,$(SRC:.c=.o))

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
$(NAME): $(O_P) $(OBJ) $(LFT_D)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

# Compiles each source file individually.
$(O_P)/%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Creates the folder for the object files.
$(O_P):
	mkdir $(O_P)

# Removes all temporary files.
clean:
	- $(RM) $(H_O) $(OBJ) *~
	- $(MAKE) -C $(LFT_P) clean
	- find . -name \*~ -print -delete

# Removes everything created by this makefile.
fclean: clean
	- $(RM) $(NAME)
	- $(RM) -r $(O_P)
	- $(MAKE) -C $(LFT_P) fclean

# Removes all files created by this makefile and recompiles the project.
re: fclean all

# A list with all always dirty rules.
.PHONY: all clean flcean re bonus norm run
