/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:15:50 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/11 19:34:35 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_init_game(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_sprites(t_game *game);

void	ft_init_game(t_game *game)
{
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;
    game->movements = 0;
    game->enemy_k_num = 0;
    game->enemy_k = NULL;
    game->map.columns = ft_strlen(game->map.full[0]) - 1;
    while (game->map.full[game->map.rows])
        game->map.rows++;
    game->player_direction = FRONT;
    ft_init_mlx(game);
    ft_init_sprites(game);
    ft_printf(GREEN"Game initialization successful!\n"RESET);
}

void ft_init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
    game->win_ptr = mlx_new_window(
        game->mlx_ptr,
        (game->map.columns + 1) * IMG_WIDTH,
        game->map.rows * IMG_HEIGHT,
        "so_long"
    );
    if (!game->win_ptr)
    {
        free(game->mlx_ptr);
        ft_error_msg("Couldn't create the Window.", game);
    }
}

void ft_load_sprite(t_image *sprite, void *mlx, char *path, t_game *game)
{
    t_image *temp = malloc(sizeof(t_image));
    if (!temp)
        ft_error_msg("Memory allocation failed for sprite.", game);

    temp->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &temp->x, &temp->y);
    ft_printf(CYAN"Loading sprite from path: %s\n"RESET, path);

    if (!temp->xpm_ptr)
    {
        ft_printf(RED"Failed to load sprite: %s\n"RESET, path);
        free(temp);
        ft_error_msg("Couldn't find a sprite. Does it exist?", game);
    }
    *sprite = *temp;
    free(temp);
}

void ft_init_sprites(t_game *game)
{
    void *mlx = game->mlx_ptr;

    ft_load_sprite(&game->wall, mlx, WALL_XPM, game);
    ft_load_sprite(&game->floor, mlx, FLOOR_XPM, game);
    ft_load_sprite(&game->coins, mlx, COINS_XPM, game);
    ft_load_sprite(&game->player_front, mlx, PLAYER_FRONT_XPM, game);
    ft_load_sprite(&game->player_left, mlx, PLAYER_LEFT_XPM, game);
    ft_load_sprite(&game->player_right, mlx, PLAYER_RIGHT_XPM, game);
    ft_load_sprite(&game->player_back, mlx, PLAYER_BACK_XPM, game);
    ft_load_sprite(&game->open_exit, mlx, OPEN_EXIT_XPM, game);
    ft_load_sprite(&game->exit_closed, mlx, EXIT_CLOSED_XPM, game);
    
}