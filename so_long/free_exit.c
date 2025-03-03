/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:17:21 by maskour           #+#    #+#             */
/*   Updated: 2025/02/27 15:56:21 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game_mnag *map_data)
{
	int	i;

	i = 0;
	if (!map_data)
		return ;
	if (map_data->map)
	{
		while (i < map_data->map_hight)
		{
			free(map_data->map[i]);
			i++;
		}
		free(map_data->map);
	}
}

void	free_images(t_game_mnag *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_background)
		mlx_destroy_image(game->mlx, game->img_background);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
}

void	exit_game(t_game_mnag *game, int p)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(p);
}

int	close_game(t_game_mnag *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free_images(vars);
	if (vars->win)
		mlx_destroy_window (vars->mlx, vars->win);
	exit(0);
}
