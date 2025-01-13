/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:06:14 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/07 22:52:01 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <errno.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

#define VISITED 'V'

typedef struct	s_game_data 
{
	//window
    void    *mlx;
    void    *win;
    int     win_width;
    int     win_height;
    //image
    int     img_width;
    int     img_height; 
    void    *img;
    //map
    char    **map;
    char    **map_coord;
    char    **player_position;
    int     map_height; 
    int     map_width;
    int     x;
    int     y;
    int     player_x;
    int     player_y;
    int     nb_player;
    int     nb_exit;
    int     nb_collectible;
    char    type;
}	t_game_data;

int		    mouse_click(int button, int x, int y, void *param);
int 	    esc_click(int keycode, void *param);
char        **create_map_tab(t_game_data *game);
char        **save_map(t_game_data *game, const char *file_path);
char        **read_map(t_game_data *game, const char *file_path);
int 	    check_map_is_ber(char *file_path);
int         map_is_rectangular(t_game_data *game, char **map);
int         map_is_surrounded(t_game_data *game);
// void     display_map(char **map);
int         game_check(t_game_data *game);
void        init_game(t_game_data *game);
char        **copy_map(t_game_data *game);
int	        simple_error(char *s);
void        flood_fill(char **map, int x, int y, int map_width, int map_height);
void        free_map(char **map, int map_height);
int         check_valid_path(t_game_data *game);
int	        mlx_open_window(t_game_data *game);


#endif