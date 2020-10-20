# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psabreto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:23:48 by psabreto          #+#    #+#              #
#    Updated: 2020/07/11 18:20:41 by psabreto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJECTS = ft_pr/ft_printf.o ft_pr/ft_printf_part2.o ft_pr/ft_printf_part7.o \
functions/x_littel.o functions/x_big.o functions/p_function.o functions/u_function.o functions/u_function_part2.o \
0_or_32/put_0_or_32.o 0_or_32/put_0_or_32_p.o 0_or_32/put_0_or_32_c_pr.o 0_or_32/put_0_or_32_s.o 0_or_32/put_0_or_32_xx.o \
dif/put_dif.o dif/put_dif_c_pr.o dif/put_dif_xx.o dif/put_dif_s.o dif/put_dif_p.o

OBJ_LIBFT = src_libft/a_ft_atoi.o src_libft/a_ft_isascii.o src_libft/a_ft_isdigit.o \
src_libft/a_ft_putnbr_fd.o src_libft/a_ft_putchar_fd.o \
src_libft/a_ft_putstr_fd.o src_libft/a_ft_strlen.o src_libft/a_ft_isalpha.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJ_LIBFT)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc -c $(CFLAGS) -I./ -o $@ $<

clean:
	rm -f $(OBJECTS) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
