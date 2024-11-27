##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compile makefile
##

SRC	= 	src/setting_up.c 						\
		src/main.c 								\
		src/read_to_string_array.c 				\
		src/verif_error.c 						\
		src/generate_map.c 						\
		src/return_woula.c

OBJ	=	$(SRC:.c=.o)

NAME =	setting_up

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make clean -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib/ -lmy -Wall -Wextra -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re:	fclean all
