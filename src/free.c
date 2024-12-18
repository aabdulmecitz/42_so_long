/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:42:47 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/19 01:45:44 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_tripple(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
    if (ptr1)
        free(ptr1);
    if (ptr1)
        free(ptr2);
    if (ptr1)
        free(ptr3);
    if (ptr1)
        free(ptr4);    
}