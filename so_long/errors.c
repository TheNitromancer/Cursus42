/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:50:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 16:54:56 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror(t_program *mlx, char *msg)
{
	ft_printf("Error\n%s", msg);
	if (mlx->winptr)
		mlx_destroy_window(mlx->mlxptr, mlx->winptr);
	free(mlx->mlxptr);
	exit(1);
}

void	maperror(t_program *mlx, char *msg)
{
	free(mlx->map.str);
	mlx->map.str = NULL;
	printerror(mlx, msg);
}

void	textureerror(t_program *mlx, char *msg)
{
	ft_printf("Error\n%s", msg);
	imagedel(mlx);
	vanish_tiles(&mlx->map);
	exit(1);
}
