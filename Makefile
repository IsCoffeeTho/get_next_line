# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 17:51:49 by amenadue          #+#    #+#              #
#    Updated: 2022/02/24 10:12:50 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCDIR = srcs/

SRCS = 	get_next_line.c \
		get_next_line_utils.c


FILES = $(addprefix $(SRCDIR),$(SRCS))
OBJS = $(FILES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) -c $(CFLAGS) -I headers $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(NAME) $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
