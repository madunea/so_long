/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:05:17 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/13 13:47:29 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_open_window(t_game_data *game)
{	
	game->img_width = 10;
	game->img_height = 10;
	
	game->mlx = mlx_init();
	if (game->mlx == NULL) 
	{
        printf("Erreur d'initialisation de MiniLibX.\n");
       	return (EXIT_FAILURE);
    }
	game->win = mlx_new_window(game->mlx, 1800, 1600, "so_long");
	game->img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &game->img_width, &game->img_height);
   	if (!game->img) 
	{
        printf("Erreur de chargement de l'image XPM\n");
        return (EXIT_FAILURE);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, game->img_width, game->img_height);
	// mlx_mouse_hook(win, mouse_click, NULL);
	mlx_key_hook(game->win, esc_click, game);
	mlx_loop(game->mlx);
	return (0);
}


// int mlx_open_window(t_game_data *game)
// {   
//     game->mlx = mlx_init();
//     if (game->mlx == NULL) 
//     {
//         printf("Erreur d'initialisation de MiniLibX.\n");
//         return 1;
//     }
//     game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
//     mlx_key_hook(game->win, esc_click, game);
//     mlx_loop(game->mlx);
//     return (0);
// }
