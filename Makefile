CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = server.c client.c
OBJ = $(SRC:.c=.o)

all: server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o
	$(CC) $(CFLAGS) -o $@ $^

client: client.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
