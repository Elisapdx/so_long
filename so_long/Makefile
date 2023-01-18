# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisa <elisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:24:15 by elisa             #+#    #+#              #
#    Updated: 2023/01/16 17:57:30 by elisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= main.c image.c read_map.c error.c window.c \
	gnl/get_next_line_solong.c gnl/get_next_line_utils_solong.c move.c
OBJ=$(SRCS:.c=.o)

NAME= so_long
OBJS=$(SRCS:.c=.o)

all:$(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -framework OpenGL -framework AppKit libmlx.a -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJS_LIB) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAMEM) $(NAME_BONUS)

re: fclean all