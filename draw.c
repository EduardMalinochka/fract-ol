/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/24 12:34:00 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	func(t_vars *vars)
{
	int		i;
	double	temp;

	i = 0;
	while (i < vars->iteras && vars->x_val * vars->x_val + vars->y_val
		* vars->y_val < 4)
	{
		temp = vars->x_val;
		vars->x_val = vars->x_val * vars->x_val - vars->y_val * vars->y_val
			+ vars->selected_r;
		vars->y_val = 2 * temp * vars->y_val + vars->selected_i;
		i++;
	}
	return (i);
}

void	c_calc(t_vars *vars, int *x, int *y)
{
	vars->selected_r = ((*x - WIDTH / 2.0) / vars->zoom) + vars->vertical_swift;
	vars->selected_i = ((*y - HEIGHT / 2.0) / vars->zoom)
		+ vars->horizontal_swift;
	vars->y_val = 0;
	vars->x_val = 0;
}

void	draw_mandel(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	y = -1;
	i = 0;
	black_screen(vars);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c_calc(vars, &x, &y);
			i = func(vars);
			color_change(vars, i);
			if ((vars->x_val * vars->x_val + vars->y_val * vars->y_val) < 4)
				put_pixel_in_img(vars, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(vars, x, y, create_trgb(0, vars->c1, vars->c2,
						vars->c3));
		}
	}
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.image,
		0, 0);
}

void	draw_julia(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	y = -1;
	i = 0;
	black_screen(vars);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			vars->x_val = ((x - WIDTH / 2.0) / vars->zoom) + vars->vertical_swift;
			vars->y_val = ((y - HEIGHT / 2.0) / vars->zoom) + vars->horizontal_swift;
			i = func(vars);
			color_change(vars, i);
			if ((vars->x_val * vars->x_val + vars->y_val * vars->y_val) < 4)
				put_pixel_in_img(vars, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(vars, x, y, create_trgb(0, vars->c1, vars->c2, vars->c3));
		}
	}
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.image, 0, 0);
}

void	black_screen(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			put_pixel_in_img(vars, i, j, 0X000000);
	}
}
