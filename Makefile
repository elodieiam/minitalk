PRINTF_DIR = ft_printf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : ft_printf server client

ft_printf :
	make -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/libftprintf.a .
	make -C $(PRINTF_DIR) clean

server : server.c libftprintf.a minitalk.h
	$(CC) $(CFLAGS) server.c -L. -lftprintf -o $@

client : client.c libftprintf.a minitalk.h
	$(CC) $(CFLAGS) client.c -L. -lftprintf -o $@

clean :
	rm -f client.o server.o

fclean : clean
	rm -f client server libftprintf.a 

re : fclean all

.PHONY : ft_printf all clean fclean re 

#ici, -o $@ indique qu'on donne pour nom à l'exécutable la cible actuelle, donc server ou client c'est équivalent à -o client ou -o server

