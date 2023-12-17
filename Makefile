SERVER_SRCS	= server.c
CLIENT_SRCS	= client.c
UTILS_SRCS 	= utils.c
UTILS_OBJS	= $(UTILS_SRCS:.c=.o)
HEADERS		= inc/minitalk.h

CC			= cc -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft
INC = -I inc

all:		libft server client

libft:
			@make -C libft

server:		${HEADERS} utils $(SERVER_SRCS) 
			$(CC) $(CFLAGS) $(SERVER_SRCS) $(UTILS_OBJS) $(INC) ./libft/Libft.a -o server

client:		${HEADERS} utils $(CLIENT_SRCS)
			$(CC) $(CFLAGS) $(CLIENT_SRCS) $(UTILS_OBJS) $(INC) ./libft/Libft.a -o client

utils :		${HEADERS} $(UTILS_SRCS)
			$(CC) $(CFLAGS) $(UTILS_SRCS) $(INC) -c -o utils.o

clean:
			@make clean -C libft

fclean:		clean
			rm -rf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
