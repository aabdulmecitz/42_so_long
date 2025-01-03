/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:38 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:08:39 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_object(t_game *game, int x, int y);
void	ft_player_move(int keycode, t_game *game);
void	ft_move_direction(t_game *game, int dx, int dy);
int		key_hook(int keycode, t_game *game);

void	ft_player_move(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player_direction = BACK;
		ft_move_direction(game, 0, -1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player_direction = FRONT;
		ft_move_direction(game, 0, 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player_direction = LEFT;
		ft_move_direction(game, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player_direction = RIGHT;
		ft_move_direction(game, 1, 0);
	}
}

void	ft_move_direction(t_game *game, int dx, int dy)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = game->map.player.x;
	y = game->map.player.y;
	if (game->map.full[y + dy][x + dx] != WALL && (game->map.full[y + dy][x
			+ dx] != MAP_EXIT || game->map.coins == 0))
	{
		ft_check_object(game, x + dx, y + dy);
		game->map.full[y][x] = FLOOR;
		game->map.player.x += dx;
		game->map.player.y += dy;
		game->map.full[y + dy][x + dx] = PLAYER;
		game->movements++;
		print_space_line(game);
		write_steps(game, 32, (game->map.rows + 1) * IMG_HEIGHT);
	}
}

void	ft_check_object(t_game *game, int x, int y)
{
	if (game->map.full[y][x] == COINS)
		game->map.coins--;
	else if (game->map.full[y][x] == MAP_EXIT && game->map.coins == 0)
	{
		ft_congrats_message();
		ft_destroy_window(game);
	}
	else if (game->map.full[y][x] == STAT_ENEMY
			|| game->map.full[y][x] == WANDER_ENEMY)
	{
		ft_failed_msg();
		ft_destroy_window(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		ft_destroy_window(game);
	ft_player_move(keycode, game);
	return (0);
}

void	ft_handle_buttons(t_game *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_destroy_window, game);
	mlx_hook(game->win_ptr, Expose, 0, ft_render_frame, game);
}
