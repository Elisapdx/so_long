/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:37:41 by elisa             #+#    #+#             */
/*   Updated: 2023/02/05 12:44:11 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				b;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	b = 0;
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while ((s[i] || d[i]) && b == 0 && i < n)
	{
		if (s[i] != d[i])
			b = s[i] - d[i];
		i++;
	}
	return (b);
}

int	verif_fichier(char *fichier)
{
	size_t	len;
	int		fd;

	len = ft_strlen(fichier);
	if (open(fichier, O_DIRECTORY) >= 0)
	{
		fd = open(fichier, O_DIRECTORY);
		close(fd);
		return (0);
	}
	else
	{
		fd = open(fichier, O_RDONLY);
		close (fd);
		if ((fichier[len - 4] != '.' && fichier[len - 3] != 'b'
				&& fichier[len - 2] != 'e'
				&& fichier[len - 1] != 'r') || fd < 0)
			return (0);
		return (1);
	}
}

int	free_double_tab(char **tab, int ret)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
	return (ret);
}

int	chemin(t_game *game, char **map_cop)
{
	if (game->map[game->y_cop][game->x_cop] == 'E')
	{
		map_cop = copy_map(game);
		if (!path_poss2(game, map_cop, game->x_cop, game->y_cop))
			return (free_double_tab(map_cop, 0));
		free_double_tab(map_cop, 0);
	}
	if (game->map[game->y_cop][game->x_cop] == 'C')
	{
		map_cop = copy_map(game);
		if (!path_poss(game, map_cop, game->x_cop, game->y_cop))
			return (free_double_tab(map_cop, 0));
		free_double_tab(map_cop, 0);
	}
	return (0);
}
