NAME = minishell

# Collors
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
RESET 	= \033[0m

# Paths
HEADERS_PATH 	= ./include/
SRCS_PATH 		= ./src/
OBJS_PATH 		= ./obj/
LIBS_PATH 		= ./lib/
BINS_PATH 		= ./bin/

# Compilation
CC 		= gcc -g
# FLAGS 	= -Wall -Wextra -Werror
FLAGS 	=

# ARGS = -422 115 655 -379 29 768

#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

# Bash commands
RM 			 = rm -f # -f Force
MKDIR 		 = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory

# Files
SRC_FILES = minishell.c \
			aux-printf.c \
			aux-malloc.c \
			aux-free.c \
			aux-write.c \
			aux-open.c \
			aux-read.c \
			aux-access.c \
			aux-execve.c \
			aux-fork.c \
			aux-pipe.c \
			aux-signal.c \
			aux-sigaction.c \
			aux-sigaction2.c \
			aux-opendir.c \
			mini-mini-shell.c

SOURCES 	= $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES 	= $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS 	= $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE 	= minishell

# Targets
all: libft $(NAME) main

# Compiles libft all over
libft:
	@echo "$(NAME): $(BLUE)Generating... Just a minute$(RESET)"
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)
	@echo "$(NAME): $(GREEN)Done!$(RESET)"

# Creates static library libft.a inside ./libs/ folder
$(NAME): $(OBJECTS)
	@cp $(LIBS_PATH)/libft.a $(LIBS_PATH)$(NAME)
	@ar -rcs $(LIBS_PATH)$(NAME) $(OBJECTS)

# Creates object files
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

# Creates the executable file $(EXECUTABLE) to test development
main:	./apps/app.c
	@$(MKDIR) $(BINS_PATH)
	@$(CC) $(FLAGS) $(OBJECTS) $< $(LIBS_PATH)$(NAME) -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

# Compile program and execute main file
run: all main
	$(BINS_PATH)$(EXECUTABLE) $(ARGS)

# Sanitize
clean:
	@echo "$(GREEN)$(NAME): $(RED)object (*.o) files were deleted$(RESET)"
	@$(RM) $(OBJECTS)
	@echo "$(RED)Clean in progres...$(RESET)"
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# Removing .o files, .a files
fclean: clean
	@echo "$(GREEN)$(NAME): $(RED)was deleted$(RESET)"
	@$(RM) $(BINS_PATH)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(NAME)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@
	@echo "$(GREEN)$(NAME): $(BLUE)Sanitized!$(RESET)"

norma:
	norminette $(SOURCES)

valgrind:
	$(LEAK) $(BINS_PATH)$(EXECUTABLE) $(ARGS)

# Removing and running
re: fclean all

# All the variables that is not a file in source folder.
.PHONY: all run clean fclean re
