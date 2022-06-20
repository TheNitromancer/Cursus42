/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:31:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 18:00:32 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vanish_tiles(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
		free(map->tile[y++]);
	free(map->tile);
	free(map->str);
	exit(0);
}

int	closer(void *program)
{
	t_program	*mlx;

	mlx = program;
	mlx_destroy_image(mlx->mlxptr, mlx->wllsprt.imptr);
	mlx_destroy_image(mlx->mlxptr, mlx->coinsprt.frame0);
	mlx_destroy_image(mlx->mlxptr, mlx->coinsprt.frame1);
	mlx_destroy_image(mlx->mlxptr, mlx->exitsprt.frame0);
	mlx_destroy_image(mlx->mlxptr, mlx->exitsprt.frame1);
	mlx_destroy_image(mlx->mlxptr, mlx->playsprt.frame0);
	mlx_destroy_image(mlx->mlxptr, mlx->playsprt.frame1);
	vanish_tiles(&mlx->map);
	return (0);
}