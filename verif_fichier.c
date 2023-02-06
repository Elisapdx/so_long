/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:37:41 by elisa             #+#    #+#             */
/*   Updated: 2023/02/06 17:24:06 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	verif_fichier(char *fichier)
{
	size_t	len;
	int		fd;

	len = ft_strlen(fichier);
	fd = open(fichier, O_DIRECTORY);
	if (fd >= 0)
	{
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
