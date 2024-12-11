/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:59:37 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/11 19:33:26 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy_list *init_enemy_list(t_game *game)
{
    t_enemy_list *list = malloc(sizeof(t_enemy_list));
    if (!list)
    {
		ft_error_msg("Memory wandering enemies failed for game", game);
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void add_enemy(t_enemy_list *list, t_enemy enemy)
{
    t_enemy_node *new_node = malloc(sizeof(t_enemy_node));
    t_enemy_node *current;
    if (!new_node)
    {
        perror("Failed to allocate memory for enemy node");
        exit(EXIT_FAILURE);
    }
    if (!list->head)
        list->head = new_node;
    else
    {
        current = list->head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
    list->count++;
}
void free_enemy_list(t_enemy_list *list)
{
    t_enemy_node *current = list->head;
    t_enemy_node *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->count = 0;
}
