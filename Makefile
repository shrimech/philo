NAME = philo

CC = cc

CFLAGS =  -Wall -Wextra -Werror -pthread -g


SRCS = philo.c parcing/private_data.c parcing/public_data.c utils/utils.c utils/print.c utils/destroying.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS)  $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	
fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all clean

.PHONY: all clean fclean re