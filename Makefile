CLIENT	=	client
SERVER	=	server

CFLAGS	=	-Wall -Wextra -Werror
CC	=	cc

INC = -I inc
CLIENT_SRCS	=	client.c
SERVER_SRCS	=	server.c
UTILS_SRCS	=	utils.c

CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)


all : $(CLIENT) $(SERVER)

$(CLIENT) : 
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(UTILS_SRCS) $(INC) ./libft/Libft.a -o $(CLIENT)

$(SERVER) :
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(UTILS_SRCS) $(INC) ./libft/Libft.a -o $(SERVER)


clean :
	$(MAKE) clean -C ./libft
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re