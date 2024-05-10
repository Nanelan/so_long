/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:57 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/10 21:34:28 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_open_door(t_map	*game, int i, int j)
{
	mlx_texture_t	*open_door;

	open_door = mlx_load_png("./assets/steps.png");
	if (!open_door)
		shit();
	game->images->open_door = mlx_texture_to_image(game->mlx, open_door);
	if (!game->images->open_door)
		shit();
	mlx_image_to_window(game->mlx, game->images->open_door, i * PIX, j * PIX);
	if (mlx_image_to_window(game->mlx, \
		game->images->open_door, i * PIX, j * PIX) < 0)
		shit();
}

void	print_map(t_map	*game)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			load_floor(game, i, j);
			if (game->map[j][i] == '1')
				load_wall(game, i, j);
			else if (game->map[j][i] == 'E')
			{
				if (game->collects == 0)
					load_open_door(game, i, j);
				else
					load_door(game, i, j);
			}
			else if (game->map[j][i] == 'C')
				load_coin(game, i, j);
			i++;
		}
		j++;
	}
	load_player(game, game->player_x, game->player_y);
}
