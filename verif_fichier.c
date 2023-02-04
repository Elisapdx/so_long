/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:37:41 by elisa             #+#    #+#             */
/*   Updated: 2023/02/03 14:23:33 by elisa            ###   ########.fr       */
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
	int		len;
	char	*extens;

	len = ft_strlen(fichier);
	if (len < 4)
		return (0);
	extens = fichier + (len - 4);
	return (!ft_strncmp(".ber", extens, 4));
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

int	chemin(t_game *game, char **map_cop, int x, int y)
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
}
