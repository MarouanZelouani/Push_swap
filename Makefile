NAME = push_swap
CHECKER = checker

HFILE = ./includes/push_swap.h
GNL_HFILE = ./includes/get_next_line.h
LIBFT_HFILE = ./includes/libft.h

SRC = ./src

CFILES = ./lib/get_next_line/get_next_line.c ./src/utils.c ./src/algo_utils.c  ./src/new_algo.c     ./lib/get_next_line/get_next_line_utils.c	checkers/execute.c src/error_checks.c src/free_stack.c  src/push_operation.c  src/reverse_r_operation.c src/rotate_operation.c src/sort.c src/sort_for_three.c  src/stack_utils.c src/swap_operation.c\
		 ./lib/libft/ft_atoi.c ./lib/libft/ft_isdigit.c  ./lib/libft/ft_memmove.c ./lib/libft/ft_split.c  ./lib/libft/ft_strlcpy.c  ./lib/libft/ft_strtrim.c\
		 ./lib/libft/ft_bzero.c  ./lib/libft/ft_isprint.c  ./lib/libft/ft_memset.c  ./lib/libft/ft_strchr.c  ./lib/libft/ft_strlen.c   ./lib/libft/ft_substr.c\
		 ./lib/libft/ft_calloc.c   ./lib/libft/ft_itoa.c     ./lib/libft/ft_putchar_fd.c  ./lib/libft/ft_strdup.c    ./lib/libft/ft_strmapi.c  ./lib/libft/ft_tolower.c\
		 ./lib/libft/ft_isalnum.c  ./lib/libft/ft_memchr.c   ./lib/libft/ft_putendl_fd.c  ./lib/libft/ft_striteri.c  ./lib/libft/ft_strncmp.c  ./lib/libft/ft_toupper.c\
		 ./lib/libft/ft_isalpha.c  ./lib/libft/ft_memcmp.c   ./lib/libft/ft_putnbr_fd.c   ./lib/libft/ft_strjoin.c   ./lib/libft/ft_strnstr.c\
		 ./lib/libft/ft_isascii.c  ./lib/libft/ft_memcpy.c   ./lib/libft/ft_putstr_fd.c   ./lib/libft/ft_strlcat.c   ./lib/libft/ft_strrchr.c\

CHECKER_C =		checkers/check_pro.c

PUSH_SWAP_C =	src/push_swap.c

OFILES = $(CFILES:.c=.o)
PUSH_SWAP_O = $(PUSH_SWAP_C:.c=.o)
CHECKER_O = $(CHECKER_C:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar rc

GREEN	=	\033[92;1m
CLEAR	=	\033[0m

all: making $(NAME)
	@echo "\033[2K\r$(GREEN)The project was built with success!$(CLEAR)"
	
making:
	@echo -n "Building the project..."

$(NAME) : $(OFILES) $(PUSH_SWAP_O)
	@$(CC) $(CFLAGS) $(OFILES) $(PUSH_SWAP_O) -o $(NAME)

$(CHECKER) : $(OFILES) $(CHECKER_O)
	@$(CC) $(CFLAGS) $(OFILES) $(CHECKER_O) -o $(CHECKER)		

bonus : $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean : 
	@$(RM) $(OFILES) $(PUSH_SWAP_O) $(CHECKER_O)
	@echo "$(GREEN)done cleaning..!$(CLEAR)"
	 
fclean : clean
	@$(RM) $(NAME) $(CHECKER) $(LIBFT)

.PHONY : clean fclean re all
