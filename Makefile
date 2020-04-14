NAME = creator

SRC =	script.cpp

OBJS =	$(SRC:.cpp=.o)

CC =	clang++

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	clang++ -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
