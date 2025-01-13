/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:10 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/09 14:08:45 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data game;
	
	if (argc != 2)  // if (argc != 2 || check_map_is_ber(argv[1]) == 1)
		simple_error("There should be 2 arguments");
	if (check_map_is_ber(argv[1]) != 0)
		simple_error("The file should be a .ber");
	// mlx_open_window(&game);
	init_game(&game);
	read_map(&game, argv[1]);
	game_check(&game);
	// printf("check ok\n");
	flood_fill(game.map, game.x, game.y, game.map_width, game.map_height);
	return (0);
}
