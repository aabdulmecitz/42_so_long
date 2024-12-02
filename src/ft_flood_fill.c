/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:33:43 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/27 19:36:26 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map *ft_copy_map(const t_map *src_map)
{
    t_map *dst_map;
    int i;

    dst_map = (t_map *)malloc(sizeof(t_map));
    if (!dst_map)
        return NULL;
    *dst_map = *src_map;
    dst_map->full = (char **)malloc(sizeof(char *) * dst_map->rows);
    if (!dst_map->full)
        return (free(dst_map), NULL);
    i = 0;
    while (i < dst_map->rows)
    {
        dst_map->full[i] = ft_strdup(src_map->full[i]);
        if (!dst_map->full[i])
        {
            while (i--)
                free(dst_map->full[i]);
            return (free(dst_map->full), free(dst_map), NULL);
        }
        i++;
    }
    return dst_map;
}

static void flood_fill(t_map *map, int x, int y, int *collected)
{
    if (x < 0 || x >= map->columns || y < 0 || y >= map->rows || 
        map->full[y][x] == WALL || 
        map->full[y][x] == 'F' || 
        map->full[y][x] == MAP_EXIT)
        return;
    if (map->full[y][x] == COINS)
        (*collected)++;
    map->full[y][x] = 'F';
    flood_fill(map, x + 1, y, collected);
    flood_fill(map, x - 1, y, collected);
    flood_fill(map, x, y + 1, collected);
    flood_fill(map, x, y - 1, collected);
}

int ft_check_all_collectables(t_map *map, t_game *game)
{
    int x;
    int y;
    int collected;
    
    x = game->map.player.x;
    y = game->map.player.y;
    collected = 0;
    flood_fill(map, x, y, &collected);
    return collected == map->coins;
}

void check_as_a_hero(t_game *game)
{
    t_map *clone_map;
    int result;

    if (WIN_W >= (game->map.columns * IMG_WIDTH) && WIN_H >= (game->map.rows * IMG_HEIGHT))
    {
        ft_printf("rows %d, columns %d\n", game->map.rows, game->map.columns);
        ft_printf(GREEN"Map validation passed!\n"RESET);
    }
    else
        ft_error_msg("The map is too large for your display.\nYou can set display size with -D", game);
    clone_map = ft_copy_map(&game->map);
    if (!clone_map)
    {
        ft_error_msg("Map copy failed.", game);
        return;
    }
    result = ft_check_all_collectables(clone_map, game);
    if (result)
        ft_printf(GREEN"Passed from flood fill\n"RESET);
    else
        ft_error_msg("All of coins can't be collected.", game);
    ft_free_just_map(clone_map);
}
