/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:42:21 by elisa             #+#    #+#             */
/*   Updated: 2023/02/03 12:43:48 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_wwin(int coin, int nb_coin)
{
	if (coin == nb_coin)
	{
		write(1, "Vous êtes sorti du jeu\n", 25);
		exit(0);
	}
	else
		write(1, "Pas assez de coins pour fuir !\n", 32);
}

/* up = 13 || 126
down = 1 || 125
right = 2 || 124
left = 0 || 123 */
int	key_hook(int keycode, void *game)
{
	t_game	*key;

	key = (t_game *) game;
	if (keycode == 2 || keycode == 124)
		move(key, 1, 0);
	else if (keycode == 0 || keycode == 123)
		move(key, -1, 0);
	else if (keycode == 13 || keycode == 126)
		move(key, 0, -1);
	else if (keycode == 1 || keycode == 125)
		move(key, 0, 1);
	else if (keycode == 53)
	{
		write(1, "Vous avez quitté le jeu\n", 26);
		exit(0);
	}
	return (1);
}

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
