/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 05:38:38 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/26 20:03:47 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    ft_render_frame(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (game->map.full[y][x] == WALL)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
            else if (game->map.full[y][x] == FLOOR)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
            else if (game->map.full[y][x] == PLAYER)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_front.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);    
            else if (game->map.full[y][x] == COINS)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coins.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
            else if (game->map.full[y][x] == MAP_EXIT)
            {
                if (game->map.coins == 0)
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->open_exit.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
                else
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_closed.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
            }
            x++;
        }
        y++;
    }
    return (0);
}
