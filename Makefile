PRINTF_DIR = ft_printf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : ft_printf server client

ft_printf :
	make -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/libftprintf.a .
#make -C $(PRINTF_DIR) clean

server : server.c libftprintf.a minitalk.h
	$(CC) $(CFLAGS) server.c -L. -lftprintf -o $@

client : client.c libftprintf.a minitalk.h
	$(CC) $(CFLAGS) client.c -L. -lftprintf -o $@

clean :
	rm -f client.o server.o

fclean : clean
	rm -f client server libftprintf.a
	make -C $(PRINTF_DIR) fclean

re : fclean all

.PHONY : ft_printf all clean fclean re 


