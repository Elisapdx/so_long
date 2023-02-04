# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:24:15 by elisa             #+#    #+#              #
#    Updated: 2023/02/04 18:15:29 by epraduro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= main.c image.c read_map.c error.c move.c error_resolver.c verif_fichier.c\
	gnl/get_next_line_solong.c gnl/get_next_line_utils_solong.c

SRCS_BONUS = bonus/main.c bonus/image.c bonus/read_map.c bonus/file_utils.c\
		bonus/error.c bonus/move.c bonus/error_resolver.c\
	gnl/get_next_line_solong.c gnl/get_next_line_utils_solong.c

NAME= so_long
NAME_BONUS= so_long_bonus
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all:$(NAME)

%.o: %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -lmlx  -framework OpenGL -framework AppKit -o $(NAME)
	
bonus:$(OBJS_BONUS)
	gcc $(CFLAGS) $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
