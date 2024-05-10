/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:02:08 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/10 21:54:19 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_ber(char *argv)
{
	int		i;
	char	*ber;

	ber = ".ber";
	i = ft_strlen(argv) - 4;
	if (i < 4)
		shit();
	if (ft_strcmp(&argv[i], ber) == 0)
		return (1);
	else
		shit();
	return (0);
}

int	check_errors(t_map *game, char *argv)
{
	if (check_rect(game) && check_walls(game) && check_collect(game)
		&& check_ep(game) && check_letters(game) && floodfill(&argv[1], game)
		&& check_ber(argv))
		return (1);
	return (0);
}

int	check_exit(t_map *game, char let)
{
	if (let == 'E' && game->collects == 0)
	{
		write(1, "¡Enhorabuena! 🎮🏆\n", 23);
		exit(1);
	}
	if (let == 'E' && game->collects != 0)
	{
		write(1, "Necesitas recoger todos los consumibles!\n", 41);
		return (1);
	}
	else
		shit ();
}
