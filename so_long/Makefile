# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:24:15 by elisa             #+#    #+#              #
#    Updated: 2023/01/18 17:22:23 by epraduro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= main.c image.c read_map.c error.c window.c \
	gnl/get_next_line_solong.c gnl/get_next_line_utils_solong.c move.c
OBJ=$(SRCS:.c=.o)

NAME= so_long
OBJS=$(SRCS:.c=.o)

all:$(NAME)

%.o: %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
clean:
	rm -f $(OBJ) $(OBJS_LIB) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAMEM) $(NAME_BONUS)

re: fclean all