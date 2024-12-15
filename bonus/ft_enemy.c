/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:59:37 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/15 21:07:01 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_init_enemy(t_game *game)
{
    int x;
    int y;
    t_enemy *new_enemy;

    game->enemy = NULL;
    y = 0;

    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (game->enemy_x_num == 0)
                return;
            if (game->map.full[y][x] == WANDER_ENEMY)
            {
                new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
                if (!new_enemy)
                    return;
                new_enemy->x = x;
                new_enemy->y = y;
                new_enemy->next = game->enemy;
                game->enemy = new_enemy;
                game->enemy_x_num--;
            }
            x++;
        }
        y++;
    }
}



// void    ft_enemies(t_game *game)
// {
//     // ft_allocate_enemy_memory(game);
//     ft_init_enemy(game); 
// }

// void ft_init_enemy(t_game *game)
// {
//     int x;
//     int y;

//     y = 0;
//     while (y < game->map.rows)
//     {
//         x = 0;
//         while (x < game->map.columns)
//         {
//             handle_enemy(game, x, y);
//             x++;
//         }
//         y++;
//     }
// }

// void handle_enemy(t_game *game, int x, int y)
// {
//     if (game->map.full[y][x] == STAT_ENEMY)
//     {
//         if (game->enemy_k_num > 0)
//         {
//             game->enemy_k[game->enemy_k_num - 1].pos.x = x;
//             game->enemy_k[game->enemy_k_num - 1].pos.y = y;
//             game->enemy_k[game->enemy_k_num - 1].type = ENEMY_FIXED;
//             game->enemy_k[game->enemy_k_num - 1].dir = rand() % 4; // Başlangıç yönünü rastgele ayarlayalım
//             ft_load_sprite(&game->enemy_k[game->enemy_k_num - 1].sprite, game->mlx_ptr, STAT_ENEMY_XPM, game);
//             game->enemy_k_num--;
//         }
//     }
//     else if (game->map.full[y][x] == WANDER_ENEMY)
//     {
//         if (game->enemy_x_num > 0)
//         {
//             game->enemy_x[game->enemy_x_num - 1].pos.x = x;
//             game->enemy_x[game->enemy_x_num - 1].pos.y = y;
//             game->enemy_x[game->enemy_x_num - 1].type = ENEMY_WANDERING;
//             game->enemy_x[game->enemy_x_num - 1].dir = rand() % 4; // Başlangıç yönünü rastgele ayarlayalım
//             ft_load_sprite(&game->enemy_x[game->enemy_x_num - 1].sprite, game->mlx_ptr, WANDER_ENEMY_XPM, game);
//             game->enemy_x_num--;
//         }
//     }
// }


// void ft_allocate_enemy_memory(t_game *game)
// {
//     if (game->enemy_k_num > 0)
//     {
//         game->enemy_k = malloc(game->enemy_k_num * sizeof(t_enemy));
//         if (!game->enemy_k)
//             ft_error_msg("Failed to allocate memory for stationary enemies.", game);
//     }
//     if (game->enemy_x_num > 0)
//     {
//         game->enemy_x = malloc(game->enemy_x_num * sizeof(t_enemy));
//         if (!game->enemy_x)
//             ft_error_msg("Failed to allocate memory for wandering enemies.", game);
//     }
// }

