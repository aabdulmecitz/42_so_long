/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/11 19:29:56 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

int	ft_close_game(t_game *game, t_enemy_list *list)
{
	ft_free_all_allocated_memory(game, list);
	
	ft_printf(GREEN"Game closed successfully.\n"RESET);
	exit(0);
	return (0);
}

void ft_print_map_full(t_game *game)
{
    int i;

    for (i = 0; i < game->map.rows; i++)
    {
        ft_printf("%s|size: %d\n", game->map.full[i], (int)ft_strlen(game->map.full[i]));
    }
}

int	main(int argc, const char *argv[])
{
	t_game	*game;
	t_enemy_list *wandering_enemies;
	
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_msg("Memory allocation failed for game", game);

	ft_check_command_line_args(argc, argv, game);
	ft_init_map(game, (char *)argv[1]);
	ft_init_game(game);
	ft_check_map(game);
	init_enemy_list(wandering_enemies);
	ft_printf("Map column: %d\n", game->map.columns);
	wandering_enemies = init_enemy_list(game);	
	ft_printf("player's x = %d, player's y = %d\n", game->map.player.x, game->map.player.y);
	mlx_loop_hook(game->mlx_ptr, ft_render_frame, game);
	//ft_handle_buttons(game, wandering_enemies);
	
	mlx_loop(game->mlx_ptr);
	return (0);
}



