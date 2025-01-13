/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduneau <maduneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:04:39 by maduneau          #+#    #+#             */
/*   Updated: 2024/12/05 18:23:33 by maduneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int check_map_is_ber(char *file_path)
{
    size_t len;
    
    len = ft_strlen(file_path);
    if (len < 4 || ft_strncmp(file_path + len - 4, ".ber", 4) != 0)
    {
        write(2, "Error\n File name is not .ber\n", 30);
        exit(EXIT_FAILURE);
    }
    return (0);
}
