NAME = minitalk
PRINTF_DIR = ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ft_printf client server bonus

ft_printf:
	make -C $(PRINTF_DIR)

client: client.c minitalk.h 
	$(CC) $(CFLAGS) client.c -L$(PRINTF_DIR) -lftprintf -o client

server: server.c minitalk.h
	$(CC) $(CFLAGS) server.c -L$(PRINTF_DIR) -lftprintf -o server

bonus : ft_printf client_bonus server_bonus 

client_bonus :
	$(CC) $(CFLAGS) client_bonus.c -L$(PRINTF_DIR) -lftprintf -o client_bonus

server_bonus :
	$(CC) $(CFLAGS) server_bonus.c -L$(PRINTF_DIR) -lftprintf -o server_bonus

clean:
	rm -f client.o server.o client_bonus.o server_bonus.o
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f client server client_bonus server_bonus
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all ft_printf clean fclean re