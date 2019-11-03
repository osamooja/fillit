NAME = fillit

SRCS = parser.c map.c shift.c solver.c validation.c main.c ../libft/*.c

OBJS = parser.o map.o shift.o solver.o validation.o main.o ../libft/*.o

HDR = fillit.h

LIBHDR = ../libft/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc -o $(NAME) $(SRCS) $(FLAGS) -I $(HDR) -I $(LIBHDR) 

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
