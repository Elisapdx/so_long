/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:41:26 by elisa             #+#    #+#             */
/*   Updated: 2023/02/03 14:24:14 by elisa            ###   ########.fr       */
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
	int			collect;
	int			line_count;
	int			colone_count;
	int			limit_x;
	int			old_x;
	int			old_y;
	int			nb_move;
	int			x_cop;
	int			y_cop;
	t_window	window;
	t_bdd		bdd;
	t_player	player;
}				t_game;

/****************FONCTIONS****************/

/* read_map.c */

void		null_error(char *str);
static int	linecount_map(char *file, t_game *game);
static char	**check_alloc_map(char *file, t_game *game);
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

/* move.c */

void		ft_putnbr_fd(int n, int fd);
void		move_player(t_game *game, int x_inc, int y_inc);
void		exit_wwin(int coin, int nb_coin);
void		move(t_game *game, int x_inc, int y_inc);
int			key_hook(int keycode, void *game);

/* error_resolver.c */

char		*ft_strdup(const char *s1);
char		**copy_map(t_game *game);
int			resolver_map(t_game *game);
int			path_poss(t_game *game, char **map_cop, int x, int y);
int			path_poss2(t_game *game, char **map_cop, int x, int y);

/* main.c */

t_window	new_window(t_game *game, int widht, int height, char *name);
int			error(char *str);
int			exit_window(t_game *game);
void		start_game(char *fichier, t_game *game);
int			main(int argc, char **argv);

/* verif_fichier.c */

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			verif_fichier(char *fichier);
int			free_double_tab(char **tab, int ret);
int			chemin(t_game *game, char **map_cop, int x, int y);

#endif