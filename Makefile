NAME = push_swap
CHECKER = check

HFILE = ./includes/push_swap.h
GNL_HFILE = ./includes/get_next_line.h
LIBFT_HFILE = ./includes/libft.h

LIBFT = libft.a
LIBFTFOLDER = ./libft
SRC = ./src

CFILES = ./lib/get_next_line/get_next_line.c  ./lib/get_next_line/get_next_line_utils.c	checker/execute.c src/error_checks.c src/free_stack.c src/push_cases.c src/push_operation.c  src/reverse_r_operation.c src/rotate_operation.c src/sort.c src/sort_for_five.c src/sort_for_three.c src/stack_utils_2.c src/stack_utils.c src/swap_operation.c

CHECKER_C =		checker/check.c

PUSH_SWAP_C =	src/push_swap.c

OFILES = $(CFILES:.c=.o)
PUSH_SWAP_O = $(PUSH_SWAP_C:.c=.o)
CHECKER_O = $(CHECKER_C:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar rc

all: $(NAME)

makelibft :
		@make -C $(LIBFTFOLDER)
		@cp $(LIBFTFOLDER)/$(LIBFT) .

$(NAME) : makelibft $(OFILES) $(PUSH_SWAP_O)
		@$(CC) $(CFLAGS) $(OFILES) $(PUSH_SWAP_O) $(LIBFT) -o $(NAME)

$(CHECKER) : makelibft $(OFILES) $(CHECKER_O)
		@$(CC) $(CFLAGS) $(OFILES) $(CHECKER_O)  $(LIBFT) -o $(CHECKER)


bonus : $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean : 
	@$(RM) $(OFILES)
	@cd $(LIBFTFOLDER) && make clean
	 
fclean : clean
	@$(RM) $(NAME)
	@cd $(LIBFTFOLDER) && make fclean

.PHONY : clean fclean re all
