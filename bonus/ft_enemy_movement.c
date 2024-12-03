/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:42:34 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/04 02:56:27 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_enemy_movement(t_game *game, t_enemy *enemy)
{
    int new_x;
    int new_y;

    new_x = enemy->pos.x;
    new_y = enemy->pos.y;
    if (enemy->dir == BACK)
        new_y--;
    else if (enemy->dir == FRONT)
        new_y++;
    else if (enemy->dir == RIGHT)
        new_x++;
    else if (enemy->dir == LEFT)
        new_x--;
    
    if (is_valid_position(game, new_x, new_y))
    {
        game->map.full[enemy->pos.y][enemy->pos.x] = FLOOR;
        enemy->pos.x = new_x;
        enemy->pos.y = new_y;
        game->map.full[new_y][new_x] = WANDER_ENEMY;
    }
    else
        enemy->dir = rand() % 4;
}

int is_valid_position(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->map.columns || y < 0 || y >= game->map.rows)
        return 0;
    if (game->map.full[y][x] == WALL || game->map.full[y][x] == STAT_ENEMY || 
        game->map.full[y][x] == WANDER_ENEMY || game->map.full[y][x] == COINS)
        return 0;
    return 1;
}