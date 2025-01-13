/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:51:08 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/06 13:49:47 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Parsing
    map is rectangular
    map is surrounded by walls
    map has 1+ collectibles
    map has only 1 : player, exit
map shows a valid path
collectibles are collectible (not surrounded by walls)
*/

int    map_is_rectangular(t_game_data *game, char **map)
{
    size_t  i;
    size_t  len; 

    i = 0;
    len = ft_strlen(map[0]);
    if (!map || !map[0])
    {
            printf("Error : \nThere is no map\n");
            return(1);
    }
    while((int)i < game->map_height)
    {
        // printf("len = %zu, strlen %zu = %zu\n", len, i, ft_strlen(map[i]));
        if (ft_strlen(map[i]) != len)
        {
            printf("Error : \nMap is not rectangular\n");
            return(1);
        }
        i++;
    }
    return (0);
}

int map_is_surrounded(t_game_data *game)
{
    int i;
    int j;
    
    i = 0;
    while(i < game->map_height)
    {
        j = 0;
        while(j < game->map_width)
        {
            if (i == 0 || i == game->map_height - 1 || j == 0 || j == game->map_width - 1)
            {
                if (game->map[i][j] != '1')
                {
                    printf("Error : \nMap is not surrounded by walls\n");
                    return (1);
                }
            }
        j++;
        }
    i++;
    }
    return (0);
}

int     map_has_game_assets(t_game_data *game)
{
    int i;
    int j;
    
    game->nb_player = 0;
    game->nb_exit = 0;
    game->nb_collectible = 0;
    i = 0;
    while(i < game->map_height)
    {
       j = 0;
       while (j < game->map_width)
       {
        if (game->map[i][j] == 'P')
            game->nb_player++;
        if (game->map[i][j] == 'E')
            game->nb_exit++;
        if (game->map[i][j] == 'C')
            game->nb_collectible++;
       j++;
       }
       i++;
    }
    if (game->nb_player != 1 || game->nb_exit != 1 || game->nb_collectible < 1)
    {    
        printf("Error : \nMap assets requirements are not met\n");
        return (1);
    }
    return(0);
}

int     game_check(t_game_data *game)
{
    if(map_is_rectangular(game, game->map) == 1)
        exit(EXIT_FAILURE);
    if(map_is_surrounded(game) == 1)
        exit(EXIT_FAILURE);
    if(map_has_game_assets(game) == 1)
        exit(EXIT_FAILURE);
    return(0);
}

// int main(void)
// {
//     t_game_data game;
//       char *map_correct[] = 
//       {
//         "111",
//         "111",
//         "111",
//         "111",
//         NULL
//       };
      
//       char *map_not_correct_1[] = 
//       {
//         "111",
//         "111",
//         "111",
//         "101",
//         NULL
//       };
      
//       char *map_not_correct_2[] = 
//       {
//         "111",
//         "111",
//         "111",
//         "110",
//         NULL
//       };
//     // map_is_rectangular(map);
//     map_is_surrounded(game);
//     map_is_surrounded(map_not_correct_1);
//     map_is_surrounded(map_not_correct_2);
//     return (0);
// }
 

