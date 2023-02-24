/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:38 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/24 15:28:18 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_complex_list(t_vars *vars)
{
	vars->julia_r[0] = 0.285;
	vars->julia_i[0] = 0.01;
	vars->julia_r[1] = -0.7269;
	vars->julia_i[1] = 0.1889;
	vars->julia_r[2] = -0.70176;
	vars->julia_i[2] = -0.3842;
	vars->julia_r[3] = -0.8;
	vars->julia_i[3] = 0.156;
	vars->julia_r[4] = -0.512511498387847167;
	vars->julia_i[4] = 0.521295573094847167;
	vars->julia_r[5] = -0.156844471694257101941;
	vars->julia_i[5] = -0.649707745759247905171;
	vars->julia_r[6] = -0.500934515513869749377;
	vars->julia_i[6] = -0.52287731735700945607;
	vars->julia_r[7] = -1.125;
	vars->julia_i[7] = 0.21650635094611;
	vars->julia_r[8] = -0.220858;
	vars->julia_i[8] = -0.650752;
}

void	init_img(t_vars *vars)
{
	int	bpp;
	int	sizeline;
	int	endian;

	vars->img.image = mlx_new_image(vars->img.mlx, WIDTH, HEIGHT);
	vars->img.data = mlx_get_data_addr(vars->img.image, &bpp, &sizeline,
			&endian);
	vars->img.bpp = bpp;
	vars->img.sizeline = sizeline;
	vars->img.endian = endian;
}

void	init_vars(t_vars *vars)
{
	vars->x_val = 0;
	vars->y_val = 0;
	vars->x = 0;
	vars->y = 0;
	vars->vertical_swift = 0;
	vars->horizontal_swift = 0;
	vars->zoom = 300.0;
	vars->color = 0;
	vars->img.mlx = mlx_init();
	vars->img.win = mlx_new_window(vars->img.mlx, WIDTH, HEIGHT, "Fract-ol");
	init_img(vars);
	julia_complex_list(vars);
}

void	reinit_vars(t_vars *vars)
{
	{
		vars->x_val = 0;
		vars->y_val = 0;
		vars->x = 0;
		vars->y = 0;
		vars->vertical_swift = 0;
		vars->horizontal_swift = 0;
		vars->zoom = 300.0;
		choose_frac(vars);
	}
}
