/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:11:01 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/05 20:17:55 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_destroy_images(t_game *game);

void	ft_free_all_allocated_memory(t_game *game, t_enemy_list *wandering_enemies)
{
	if (!game)
		return;
	ft_destroy_images(game);
	ft_free_map(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
    if (game->enemy_k)
        free(game->enemy_k);
    free_enemy_list(wandering_enemies);
	free(game);
}

static void ft_destroy_images(t_game *game)
{
    int i;

    i = 0;
    t_image *images[] = {
        &game->wall,
        &game->floor,
        &game->coins,
        &game->player_front,
        &game->player_left,
        &game->player_right,
        &game->player_back,
        &game->exit_closed,
        &game->open_exit,
        NULL
    };

    while (images[i])
    {
        if (images[i]->xpm_ptr)
            mlx_destroy_image(game->mlx_ptr, images[i]->xpm_ptr);
        free(images[i]);
        i++;
    }
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
		return;
	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}

void	ft_free_just_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->rows)
    {
        free(map->full[i]);
        i++;
    }
    free(map->full);
    free(map);
}

int ft_destroy_window(t_game *game, t_enemy_list *list)
{	
	if (!game)
	{
		ft_free_all_allocated_memory(game, list);
        free_enemy_list(list);
	}
	
    exit(0);
	return (0);
}
