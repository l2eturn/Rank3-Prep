NAME = so_long

CFLAG = -Iminilibx-linux

LDFLAG = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJ)
			cc $(OBJ) $(LDFLAG) -o $(NAME)

%.o: %.c
	cc $(CFLAG) -c $< -o $@ 

clean :
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME)

re : fclean all
