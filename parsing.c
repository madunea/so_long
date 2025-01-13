/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:04:39 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/13 16:51:25 by marieduneau      ###   ########.fr       */
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
        printf("Error\n File name is not .ber\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}
