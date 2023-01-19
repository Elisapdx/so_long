/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:15:27 by elisa             #+#    #+#             */
/*   Updated: 2023/01/18 17:19:23 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_window	new_window(t_game *game, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(game->mlx, widht, height, name);
	return (window);
}

/*int	size_window(t_game *game, char *file)
{
	int	x;
	int	y;
	int	fd;
	// taille de x = colone_count * 40
	// taille de y = line_count * 40
}*/
