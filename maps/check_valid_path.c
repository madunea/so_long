/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:26:31 by marieduneau       #+#    #+#             */
/*   Updated: 2025/01/07 18:19:50 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **copy_map(t_game_data *game)
{
    char    **temp_map;
    int     i;

    temp_map = malloc(sizeof(char *) * game->map_height);
    if (temp_map == NULL)
        return NULL;
    i = 0;
    while (i < game->map_height)
    {
        temp_map[i] = malloc(sizeof(char) * (game->map_width + 1));
        if (temp_map[i] == NULL)
        {
            while (i > 0)
            {
                i--;
                free(temp_map[i]);
            }
            free(temp_map);
            return NULL;
        }
    ft_strlcpy(temp_map[i], game->map[i], game->map_height);
    i++;
    }
    return(temp_map);
}

void flood_fill(char **map, int x, int y, int map_width, int map_height)
{   
    if (x < 0 || y < 0 || x >= map_height || y >= map_width)
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    map[y][x] = 'V';
    
    flood_fill(map, x + 1, y, map_width, map_height);
    flood_fill(map, x - 1, y, map_width, map_height);
    flood_fill(map, x, y + 1, map_width, map_height);
    flood_fill(map, x, y - 1, map_width, map_height);
}

void free_map(char **map, int map_height)
{
    int i;
 
    i = 0;
    while (i < map_height)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int check_valid_path(t_game_data *game)
{
    int i;
    int j;
    char    **temp_map;

    temp_map = copy_map(game);
    if (temp_map == NULL)
		simple_error("Error while copying map!");
    flood_fill(temp_map, game->player_x, game->player_y, game->map_width, game->map_height);
    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if ((game->map[i][j] == 'C' && temp_map[i][j] != 'V') || (game->map[i][j] == 'E' && temp_map[i][j] != 'V'))
            {
                free_map(temp_map, game->map_height);
                return (1);
            }
            j++;
        }
        i++;
    }
    i = 0;
    free_map(temp_map, game->map_height);
    return (0);
}

// int check_valid_path(t_game_data *game)
// {
//     int i;
//     int j;
//     char    **temp_map;

//     temp_map = copy_map(game);
//     if (temp_map == NULL)
// 		simple_error("Error while copying map!");
//     // {
//     //     perror("Failed to copy the map");
//     //     return 1;
//     // }
//     flood_fill(temp_map, game->player_x, game->player_y, game->map_width, game->map_height);
//     i = 0;
//     while (i < game->map_height)
//     {
//         j = 0;
//         while (j < game->map_width)
//         {
//             if ((game->map[i][j] == 'C' && temp_map[i][j] != 'V') || (game->map[i][j] == 'E' && temp_map[i][j] != 'V'))
//             {
//                 while (i >= 0)
//                 {
//                     free(temp_map[i]);
//                     i--;
//                 }
//                 free(temp_map);
//                 return (1);
//             }
//         j++;
//         }
//     i++;
//     }
//     i = 0;
//     while (i < game->map_height)
//     {
//         free(temp_map[i]);
//         i++;
//     }
//     free(temp_map);
//     return (0);
// }