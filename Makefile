SERVER_SRCS	= server.c utils.c
CLIENT_SRCS	= client.c utils.c
HEADERS		= inc/minitalk.h

CC			= cc -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft
INC = -I inc

all:		libft server client

libft:
			@make -C libft

server:		${HEADERS} $(SERVER_SRCS)
			$(CC) $(CFLAGS) $(SERVER_SRCS) $(INC) ./libft/Libft.a -o server

client:		${HEADERS} $(CLIENT_SRCS)
			$(CC) $(CFLAGS) $(CLIENT_SRCS) $(INC) ./libft/Libft.a -o client

clean:
			@make clean -C libft

fclean:		clean
			rm -rf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
