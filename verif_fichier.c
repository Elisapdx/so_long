/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:46:50 by epraduro          #+#    #+#             */
/*   Updated: 2023/01/23 12:44:30 by epraduro         ###   ########.fr       */
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
	int	len;
	char	*extens;
	
	len = ft_strlen(fichier);
	if (len < 4)
		return (0);
	extens = fichier + (len - 4);
	return (!ft_strncmp(".ber", extens, 4));
}
