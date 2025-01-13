/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:18:11 by maduneau          #+#    #+#             */
/*   Updated: 2025/01/07 18:15:31 by marieduneau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	simple_error(char *s)
{
	// ft_printf("ERROR\n%s\n", s);
	printf("ERROR\n%s\n", s);
	exit(EXIT_FAILURE);
}

