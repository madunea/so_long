/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:18:11 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/13 13:51:17 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int    close_window(void *param)
 {
    t_game_data *game = (t_game_data *)param;
    
    mlx_destroy_window(game->mlx, game->win);
    printf("Au revoir...");
    exit(0);
    return (0);
}

//KEYBOARD HANDLER
int keyboard_press(int keycode, void *param)
{
    t_game_data *game = (t_game_data *)param;

    if (keycode == 13) //W up
        game->player_y -= 1;
    else if (keycode == 1) //S down
        game->player_y += 1;
    else if (keycode == 0) //A left
        game->player_x -= 1;
    else if (keycode == 2) //D right
        game->player_x += 1;
    else if (keycode == 53) //ESC close win
        close_window(param);
    return (0);
}

//MOUSSE HANDLER






// int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
// mlx_key_hook(win_ptr, my_key_handler, param);
//     int my_key_handler(int keycode, void *param);

//     -> W up / S down / A left / D right 
//     -> ESC = close window 

// int my_mouse_handler(int button, int x, int y, void *param);
// mlx_mouse_hook(win_ptr, my_mouse_handler, param);
// my
//     click on screen x = close window 
    
// int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
//     mlx_hook(win_ptr, 2, 0, my_key_handler, param); // Pour écouter les touches du clavier
//     mlx_hook(win_ptr, 17, 0, close_window, param); // Pour fermer la fenêtre (événement croix)

// macOS:
// W : 13
// A : 0
// S : 1
// D : 2
// ESC : 53
// Flèche Haut : 126
// Flèche Bas : 125
// Flèche Gauche : 123
// Flèche Droite : 124

//linux:
// W : 119
// A : 97
// S : 115
// D : 100
// ESC : 65307
// Flèche Haut : 65362
// Flèche Bas : 65364
// Flèche Gauche : 65361
// Flèche Droite : 65363
    
// mlx_new_window
// mlx_key_hook
// mlx_loop

// int	mouse_click(int button, int x, int y, void *param)
// {
// 	param = NULL;
// 	x = 10;
// 	y = 10;
// 	if (button == 1)
// 		printf("Clic gauche à (%d, %d)\n", x, y);
// 	return (0);
// }

int esc_click(int keycode, void *param)
{
    t_game_data *game = (t_game_data *)param;   
    // printf("code%d\n",keycode);
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        printf("Au revoir...");
        exit(0);
    }
    return (0);
}