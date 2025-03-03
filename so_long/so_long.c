/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:44:04 by maskour           #+#    #+#             */
/*   Updated: 2025/03/01 17:13:08 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game_mnag *game)
{
	if (keycode == 2)
		go_right(game);
	else if (keycode == 1)
		go_down(game);
	else if (keycode == 0)
		go_left(game);
	else if (keycode == 13)
		go_up(game);
	else if (keycode == 53)
		close_game(game);
	return (0);
}

static int	init_game(t_game_mnag *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"./image/player.xpm", &game->img_width, &game->img_hight);
	if (!game->img_player)
		return (write(1, "Error: put image\n", 18), exit_game(game, 1), 1);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
			"./image/wall.xpm", &game->img_width, &game->img_hight);
	if (!game->img_wall)
		return (write(1, "Error: put image\n", 18), exit_game(game, 1), 1);
	game->img_background = mlx_xpm_file_to_image(game->mlx, \
			"./image/baground.xpm", &game->img_width, &game->img_hight);
	if (!game->img_background)
		return (write(1, "Error: put image\n", 18), exit_game(game, 1), 1);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
			"./image/exit.xpm", &game->img_width, &game->img_hight);
	if (!game->img_exit)
		return (write(1, "Error: put image\n", 18), exit_game(game, 1), 1);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, \
			"./image/collect.xpm", &game->img_width, &game->img_hight);
	if (!game->img_collectable)
		return (write(1, "Error: put image\n", 18), exit_game(game, 1), 1);
	return (0);
}

static int	initialize_game_data(t_game_mnag *map_data, char *map_file)
{
	if (check_file(map_file))
		return (write(1, "Error: put (.ber)in the last\n", 30), 1);
	map_data->map = read_map(map_file);
	if (!map_data->map)
		return (write(1, "Error: couldn't read the map or \
		Map size exceeds screen dimensions\n", 70), 1);
	if (validate_map(map_data))
		return (write(1, "Error: invalid map\n", 20), \
				exit_game(map_data, 1), 1);
	map_data->mlx = mlx_init();
	if (!map_data->mlx)
		return (free_map(map_data), 1);
	if (init_game(map_data))
		return (1);
	return (0);
}

static int	setup_window_and_validate(t_game_mnag *map_data)
{
	map_data->win = mlx_new_window(map_data->mlx, \
			map_data->map_width * 48, map_data->map_hight * 48, "so_long");
	if (!map_data->win)
		return (write(1, "Error:\n", 8), exit_game(map_data, 1), 1);
	if (can_reach_exit_and_coins(map_data->map, map_data) == 0)
		return (close_game(map_data), \
			write(1, "Error: couldn't reach exit or coin\n", 36), 1);
	return (0);
}


int	main(int ac, char **av)
{
	t_game_mnag	map_data;

	map_data.win = NULL;
	if (ac != 2)
		return (write(1, "Error: put the map file\n", 25), 1);
	map_data = (t_game_mnag){0};
	if (initialize_game_data(&map_data, av[1]) != 0)
		return (1);
	if (setup_window_and_validate(&map_data) != 0)
		return (1);
	game_tools(&map_data);
	mlx_key_hook(map_data.win, key_press, &map_data);
	mlx_hook(map_data.win, 17, 0, close_game, &map_data);
	mlx_loop(map_data.mlx);
	return (0);
}
