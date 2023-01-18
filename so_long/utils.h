/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:41:26 by elisa             #+#    #+#             */
/*   Updated: 2023/01/18 11:52:22 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include <unistd.h>
# include "gnl/get_next_line_solong.h"

# define WIDHT 1200
# define HEIGHT 1000

/************STRUCTS*************/

/* vector for height and weight */

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

/* window / size */

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

/* info needed for an image */

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*addr;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_bdd
{
	t_image		player;
	t_image		wall;
	t_image		exit;
	t_image		floor;
	t_image		enemy;
	t_image		coin;
}				t_bdd;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}		t_player;

/* all info for game run */

typedef struct s_game
{
	void		*mlx;
	char		**map;
	int			count_p;
	int			count_c;
	int			count_e;
	int			line_count;
	int			limit_x;
	int			old_x;
	int			old_y;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	t_bdd		bdd;
	t_player	player;
}				t_game;

/****************FONCTIONS****************/

/* read_map.c */

void		null_error(char *str);
static int	linecount_map(char *file);
static char	**check_alloc_map(char *file);
char		**read_map(char *file, t_game *game);

/* error.c */

int			error_map(t_game *game);
int			checker_map(t_game *game, int ard);
int			check_rect(t_game *game);
int			checker_line_next(t_game *game);
int			checker_map_poss(t_game *game);

/* image.c */

void		set_player(t_game *game, int x, int y);
t_image		ft_new_sprite(void *mlx, char *path);
void		put_img_to_window(t_game *game, t_image image, int x, int y);
void		load_img(t_game *game);
void		load_map(t_game *game);

/* window.c */

t_window	new_window(t_game *game, int widht, int height, char *name);

/* move.c */

void		move(t_game *game, int x_inc, int y_inc);
void		move_player(t_game *game, int x_inc, int y_inc);
int			key_hook(int keycode, void *game);
int			exit_window(t_game *game);

/* main.c */

int			error(char *str);
void		start_game(char *fichier, t_game *game);

#endif