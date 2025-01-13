


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduneau <maduneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:16 by maduneau          #+#    #+#             */
/*   Updated: 2024/11/19 17:22:45 by maduneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **create_map_tab(t_game_data *game)
{
    int     i;
    
    i = 0;
    // game->map = malloc(sizeof(char *) * game->map_height);
    game->map = calloc(game->map_height, sizeof(char *));
    if (game->map == NULL)
        return NULL;
    while (i < game->map_height)
    {
        // game->map[i] = malloc(sizeof(char) * (game->map_width + 1));
        game->map[i] = calloc(game->map_width + 1, sizeof(char));
        if (game->map[i] == NULL)
        {
            while (i > 0)
            {
                i--;
                free(game->map[i]);
            }
        free(game->map);
        return NULL;
        }
        i++;
    }
    return(game->map);
}

char    **save_map(t_game_data *game, const char *file_path)
{
    int     fd;
    char    *line;
    int     i;
    int     j;
    
    line = NULL;
    create_map_tab(game);
    if (create_map_tab(game) == NULL)
        return NULL;
    fd = open(file_path, O_RDONLY);
    if (fd == -1) 
    {
        perror("Error opening file");
        return NULL;
    }
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        // if (i >= game->map_height)  // Vérif si on dépasse la hauteur de la map
        // {
        //     free(line);
        //     break;
        // }
        j = 0;
        while (line[j] != '\0' && line[j] != '\n')
        {
            game->map[i][j] = line[j];
            j++;
        }
        game->map[i][j] = '\0';
        i++;
        free(line);
    }
    // i = 0;
    // while(i < game->map_height)   //verif visuelle à enlever
    // {
    //     printf("map%d =%s\n",i, game->map[i]);
    //     i++;
    // }
    close(fd);
    return(game->map);
}

size_t	ft_strlen_edit(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char **read_map(t_game_data *game, const char *file_path)
{
    int     fd;
    char    *line;
    int len;
    
    line = 0;
    len = 0;
    fd = open(file_path, O_RDONLY);
    if (fd == -1) 
    {
        perror("Error opening file");
        return NULL;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        len = ft_strlen_edit(line);
        if (len > game->map_width)
            game->map_width = len;
        free(line);
        game->map_height++;
    }
    close(fd);
    save_map(game, file_path);
    return 0;
}


// int main()
// {
//     int fd;
//     const char    *path;
//     char    *line;

// 	line = 0;
//     path = "maps/small_map.ber";
//     // path = "maps/invalid_surrounded_map.ber";
//     fd = open(path, O_RDONLY);

//     if (fd == -1) 
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s",line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }