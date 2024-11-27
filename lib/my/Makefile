##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compile makefile
##

SRC	= 	my_printf/my_printf.c 				\
		my_printf/flag_mini.c 				\
		my_printf/flag_o.c 					\
		my_printf/flag_u.c 					\
		my_printf/flag_hexa.c 				\
		my_printf/flag_scientific.c 		\
		my_printf/flag_float.c 				\
		my_printf/flag_diez.c				\
		my_printf/flag_hh.c 				\
		my_printf/flag_h.c 					\
		my_printf/flag_space.c 				\
		my_printf/flag_b.c 					\
		my_printf/flag_space_float.c 		\
		my_printf/flag_plus.c 				\
		my_printf/flag_ll.c 				\
		my_printf/flag_z.c 					\
		my_printf/flag_l.c 					\
		my_printf/flag_j.c 					\
		my_printf/flag_m.c 					\
		my_printf/flag_p.c 					\
		my_printf/flag_neg.c 				\
		my_printf/flag_neg_hexastring.c 	\
		my_find_prime_sup.c					\
		my_putchar.c						\
		my_showmem.c						\
		my_strcat.c							\
		my_str_islower.c					\
		my_strlen.c							\
		my_strncpy.c						\
		my_compute_power_it.c				\
		my_getnbr.c							\
		my_put_nbr.c						\
		my_showstr.c						\
		my_strcmp.c							\
		my_str_isnum.c						\
		my_strlowcase.c						\
		my_strstr.c							\
		my_compute_power_rec.c				\
		my_isneg.c							\
		my_putstr.c							\
		my_sort_int_array.c					\
		my_strcpy.c							\
		my_str_isprintable.c				\
		my_strncat.c						\
		my_strupcase.c						\
		my_compute_square_root.c			\
		my_is_prime.c						\
		my_revstr.c							\
		my_strcapitalize.c					\
		my_str_isalpha.c					\
		my_str_isupper.c					\
		my_strncmp.c						\
		my_swap.c							\
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv libmy.a ../.
	cp my.h ../../include/.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../libmy.a

re:	fclean all
