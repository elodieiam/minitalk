NAME = libftprintf.a

SRC = 	ft_printf.c\
		ft_print_element.c\
		ft_putaddr_hex.c\
		ft_putnbr.c\
		ft_putunbr.c\
		utils.c\

OBJ = $(SRC:.c=.o) 

CC = cc

FLAGS = -Wall -Wextra -Werror
	
all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@


clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
