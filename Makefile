NAME = push_swap.a
HFILE = push_swap.h
CFILES =	error_checks.c\
			stack_utils.c\
			push_operation.c\
			swap_operation.c\
			reverse_r_operation.c\
			rotate_operation.c\
			sort_for_three.c\
			push_cases.c\
			sort.c\
			stack_utils_2.c\

OFILES = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar rc

all: $(NAME)

$(NAME) : $(OFILES) $(HFILE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

re: fclean all

clean : 
	$(RM) $(OFILES)
	 
fclean : clean
	$(RM) $(NAME)

.PHONY : clean fclean re all
