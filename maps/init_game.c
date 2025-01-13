/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:13:37 by marieduneau       #+#    #+#             */
/*   Updated: 2025/01/07 22:48:03 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	init_game(t_game_data *game)
{
	game->win_width = 0;
    game->win_height = 0;
    
    game->map_width = 0;
    game->map_height = 0; 
    
    game->img_width = 0;
    game->img_height = 0;
    
    game->map = NULL;
    game->map_coord = NULL;
    game->player_position = NULL;
    game->x = 0;
    game->y = 0;
    
    game->nb_player = 0;
    game->nb_exit = 0;
    game->nb_collectible = 0;
    game->type = 0;
}

    // void    *mlx;
    // void    *win;
    // void    *img;