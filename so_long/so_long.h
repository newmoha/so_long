/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:50:41 by maskour           #+#    #+#             */
/*   Updated: 2025/02/28 15:14:53 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_player_pos
{
	int	x;
	int	y;
}	t_player_pos;

typedef struct s_game_mnag
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_player;
	void			*img_wall;
	void			*img_background;
	void			*img_exit;
	void			*img_collectable;
	char			**map;
	char			*data;
	int				found_exit;
	int				found_collectable;
	int				colleced_coins;
	int				moves_counter;
	int				map_hight;
	int				map_width;
	int				img_hight;
	int				img_width;
	t_player_pos	player_pos	;
}	t_game_mnag;

void	go_up(t_game_mnag *vars);
void	go_down(t_game_mnag *vars);
void	go_left(t_game_mnag *vars);
void	go_right(t_game_mnag *vars);
void	game_tools(t_game_mnag *game_data);
void	free_map(t_game_mnag *map_data);
void	exit_game(t_game_mnag *game, int p);
void	free_images(t_game_mnag *game);
void	put_image_win(char p, int x, int y, t_game_mnag *var);
char	**read_map(char *maps_file);
char	**copy_map(char **original, t_game_mnag *size);
void	flood_fill(char **tab, t_game_mnag *game, int x, int y);
int		check_file(char *av);
int		check_rectanglar(t_game_mnag **data);
int		check_walls(char **map);
int		check_charakters(char **map, char c, int max);
int		check_valid_charakter(char **map);
int		validate_map(t_game_mnag *data);
int		check_move(t_game_mnag *game, int y, int x);
int		key_press(int keycode, t_game_mnag *vars);
int		close_game(t_game_mnag *vars);
int		close_window(t_game_mnag *map_data);
int		count_collectables(char **map);
int		all_coins_collected(char **copied_map, t_game_mnag size);
int		can_reach_exit_and_coins(char **original_map, t_game_mnag *game);
void	update_moves(t_game_mnag *game);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

void	ft_putnbr_fd(int n, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
#endif 