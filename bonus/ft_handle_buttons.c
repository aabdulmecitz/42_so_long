/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:51:50 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/05 20:31:07 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_check_object(t_game *game, int x, int y, t_enemy_list *list);
void ft_player_move(int keycode, t_game *game, t_enemy_list *list);
void ft_move_direction(t_game *game, int dx, int dy, t_enemy_list *list);
int key_hook(int keycode, t_game *game, t_enemy_list *list);

void ft_player_move(int keycode, t_game *game, t_enemy_list *list)
{
    if (keycode == KEY_W || keycode == KEY_UP)
    {
        game->player_direction = BACK;
        ft_move_direction(game, 0, -1, list);
    }
    else if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        game->player_direction = FRONT;
        ft_move_direction(game, 0, 1, list);
    }
    else if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        game->player_direction = LEFT;
        ft_move_direction(game, -1, 0, list);
    }
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        game->player_direction = RIGHT;
        ft_move_direction(game, 1, 0, list);
    }
}


void ft_move_direction(t_game *game, int dx, int dy, t_enemy_list *list)
{
    int x = game->map.player.x;
    int y = game->map.player.y;

    if (game->map.full[y + dy][x + dx] != WALL && (game->map.full[y + dy][x + dx] != MAP_EXIT || game->map.coins == 0))
    {
        ft_check_object(game, x + dx, y + dy, list);
        game->map.full[y][x] = FLOOR;
        game->map.player.x += dx;
        game->map.player.y += dy;
        game->map.full[y + dy][x + dx] = PLAYER;
        game->movements++;
    }
    

}

void ft_check_object(t_game *game, int x, int y, t_enemy_list *list)
{
    if (game->map.full[y][x] == COINS)
        game->map.coins--;
    else if (game->map.full[y][x] == MAP_EXIT && game->map.coins == 0)
    {
        ft_congrats_message();
        ft_destroy_window(game, list);
    }
    else if (game->map.full[y][x] == STAT_ENEMY || game->map.full[y][x] == WANDER_ENEMY)
    {
        ft_failed_msg();
        ft_destroy_window(game, list);
    }

}

int key_hook(int keycode, t_game *game, t_enemy_list *list)
{   
    if (keycode == KEY_ESC || keycode == KEY_Q)
        ft_destroy_window(game, list);
    ft_player_move(keycode, game, list);
    ft_print_map_full(game);
    ft_printf(CYAN"The player's new position: (%d, %d)\nAll of coins: %d, Movements: %d\n"RESET, game->map.player.x, game->map.player.y, game->map.coins, game->movements);
    return 0;
}

void ft_handle_buttons(t_game *game, t_enemy_list *list)
{
    mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_hook, game);
    mlx_hook(game->win_ptr, DestroyNotify, 0, ft_destroy_window, game);
    mlx_hook(game->win_ptr, Expose, 0, ft_render_frame, game);
}



//int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

// KeyPress (Tuş Basma Olayı)

// Kod Numarası: 2

// Mask: 1L << 0 (KeyPressMask)

// Açıklama: Kullanıcı bir tuşa bastığında tetiklenir.

// KeyRelease (Tuş Bırakma Olayı)

// Kod Numarası: 3

// Mask: 1L << 1 (KeyReleaseMask)

// Açıklama: Kullanıcı bir tuşu bıraktığında tetiklenir.

// ButtonPress (Fare Düğmesine Basma Olayı)

// Kod Numarası: 4

// Mask: 1L << 2 (ButtonPressMask)

// Açıklama: Kullanıcı fare düğmesine bastığında tetiklenir.

// ButtonRelease (Fare Düğmesini Bırakma Olayı)

// Kod Numarası: 5

// Mask: 1L << 3 (ButtonReleaseMask)

// Açıklama: Kullanıcı fare düğmesini bıraktığında tetiklenir.

// MotionNotify (Fare Hareketi Olayı)

// Kod Numarası: 6

// Mask: 1L << 6 (PointerMotionMask)

// Açıklama: Kullanıcı fareyi hareket ettirdiğinde tetiklenir.

// Expose (Pencere Güncelleme Olayı)

// Kod Numarası: 12

// Mask: 1L << 15 (ExposureMask)

// Açıklama: Pencere güncellenmesi gerektiğinde (örneğin pencere yeniden boyutlandırıldığında veya gizlenip yeniden gösterildiğinde) tetiklenir.

// DestroyNotify (Pencere Kapanma Olayı)

// Kod Numarası: 17

// Mask: 0

// Açıklama: Pencere kapandığında tetiklenir.

//Focus In de bonus kisminda kullanabiliriz.