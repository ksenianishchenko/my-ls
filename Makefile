NAME = myls

HEADER = header.h

FLAGS = -I.

SRC = my-ls.c get-opt.c list.c print.c sort.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	gcc -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ $(NAME)
