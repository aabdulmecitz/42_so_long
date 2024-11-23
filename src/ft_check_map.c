/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:32:02 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/23 17:21:46 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_check_rectanglular(t_game *game);
void    ft_check_elements(t_game *game);
void    ft_element_counter(t_game *game);
void    ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);




void    ft_check_map(t_game *game)
{
    ft_check_rectanglular(game);
    ft_check_columns(game);
    ft_check_rows(game);
    ft_check_elements(game);    
    ft_printf(GREEN"Map validation passed!\n"RESET);
}

void    ft_check_rectanglular(t_game *game)
{
    int i;
    int first_row_len;
    int current_row_len;

    if (game->map.rows == 0)
        return;
    first_row_len = (int)ft_strlen(game->map.full[0]);
    i = 1;
    while (i < game->map.rows)
    {
        current_row_len = (int)ft_strlen(game->map.full[i]);
        if (current_row_len != first_row_len)
        {
            ft_printf(RED "%s , current row len: %d , first row len: %d\n" RESET, game->map.full[i], current_row_len, first_row_len);

            ft_error_msg("Map is not rectangular!", game);
            return;
        }
        i++;
    }
    ft_printf(GREEN "Map is rectangular!\n" RESET);
}

void    ft_check_elements(t_game *game)
{
    ft_element_counter(game);
    if (game->map.players != 1)
        ft_error_msg("Map must contain exactly one starting position ('P')", game);
    if (game->map.exit != 1)
        ft_error_msg("Map must contain exactly one exit ('E')", game);
    if (game->map.coins < 1)
        ft_error_msg("Map must contain at least one collectible ('C')", game);
}

void    ft_element_counter(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.rows)
    {
		ft_printf(CYAN"|%s| size: %d|\n" RESET, game->map.full[y], (int)ft_strlen(game->map.full[y]));
        x = 0;
        while (x < game->map.columns)
        {
            if (game->map.full[y][x] == PLAYER)
                game->map.players++;
            else if (game->map.full[y][x] == MAP_EXIT)
                game->map.exit++;
            else if (game->map.full[y][x] == COINS)
                game->map.coins++;
            else if (game->map.full[y][x] != WALL && game->map.full[y][x] != FLOOR &&
                game->map.full[y][x] != PLAYER && game->map.full[y][x] != MAP_EXIT && game->map.full[y][x] != COINS)
                ft_error_msg("Invalid character in map", game);
            x++;
        }
        y++;
    }
}

void    ft_check_surrounding_walls(t_game *game) {
    int x, y;
    for (y = 0; y < game->map.rows; y++) {
        for (x = 0; x < game->map.columns; x++) {
            // Haritanın etrafını kontrol et
            if (game->map.full[0][x] != WALL || 
                game->map.full[y][0] != WALL || 
                game->map.full[y][game->map.columns - 1] != WALL || 
                game->map.full[game->map.rows - 1][x] != WALL)
                {
                
                // Hangi durumda hata olduğunu belirlemek için ayrı ayrı hata mesajları
                if (game->map.full[0][x] != WALL) {
                    printf("Error at top row, column %d: Character is '%c', expected '%c'\n", x, game->map.full[0][x], WALL);
                }
                if (game->map.full[y][0] != WALL) {
                    printf("Error at row %d, first column: Character is '%c', expected '%c'\n", y, game->map.full[y][0], WALL);
                }
                if (game->map.full[y][game->map.columns - 1] != WALL) {
                    printf("Error at row %d, last column: Character is '%c', expected '%c'\n", y, game->map.full[y][game->map.columns - 1], WALL);
                }
                if (game->map.full[game->map.rows - 1][x] != WALL) {
                    printf("Error at bottom row, column %d: Character is '%c', expected '%c'\n", x, game->map.full[game->map.rows - 1][x], WALL);
                }

                ft_error_msg("Map is not surrounded by walls", game);
            }
        }
    }
}


void    ft_check_rows(t_game *game)
{
    int i;

    i = 0;
    printf("Checking rows...\n");
    while (i < game->map.rows)
    {
        printf("Row %d: |%s| size: %d\n", i, game->map.full[i], (int)ft_strlen(game->map.full[i]));
        if (game->map.full[i][0] != WALL)
            ft_error_msg("Invalid Map. There's a Wall missing from the first row.\nThe Map must be surrounded by walls!.", game);
        else if (game->map.full[i][game->map.columns - 1] != WALL)
            ft_error_msg("Invalid Map. There's a Wall missing from the last row.\nThe Map must be surrounded by walls!.", game);
        i++;
    }
}

void    ft_check_columns(t_game *game)
{
    int i;

    i = 0;
    printf("Checking columns...\n");
    while (i < game->map.columns)
    {
        printf("Top Row Column %d: %c\n", i, game->map.full[0][i]);
        printf("Bottom Row Column %d: %c\n", i, game->map.full[game->map.rows - 1][i]);
        if (game->map.full[0][i] != WALL)
            ft_error_msg("Invalid Map. There's a Wall missing from the first column.\nThe Map must be surrounded by walls!.", game);
        else if (game->map.full[game->map.rows - 1][i] != WALL)
            ft_error_msg("Invalid Map. There's a Wall missing from the last column.\nThe Map must be surrounded by walls!.", game);
        i++;
    }
}



