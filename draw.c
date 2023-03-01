/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/03/01 14:49:42 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterative(t_vars *vars)
{
	int		i;
	double	temp;

	i = 0;
	while (i < MAX_ITER && vars->x_val * vars->x_val + vars->y_val
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
			mandel_complex(vars, &x, &y);
			i = iterative(vars);
			color_change(vars, i);
			if ((vars->x_val * vars->x_val + vars->y_val * vars->y_val) < 4)
				put_pixel_in_img(vars, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(vars, x, y, create_trgb(0, vars->c1, vars->c2,
						vars->c3));
		}
	}
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.image, 0,
		0);
}

void	draw_julia(t_vars *v)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	y = -1;
	i = 0;
	black_screen(v);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			v->x_val = ((x - WIDTH / 2.0) / v->zoom) + v->vertical_swift;
			v->y_val = ((y - HEIGHT / 2.0) / v->zoom) + v->horizontal_swift;
			i = iterative(v);
			color_change(v, i);
			if ((v->x_val * v->x_val + v->y_val * v->y_val) < 4)
				put_pixel_in_img(v, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(v, x, y, create_trgb(0, v->c1, v->c2, v->c3));
		}
	}
	mlx_put_image_to_window(v->img.mlx, v->img.win, v->img.image, 0, 0);
}

void	draw_brain_ship(t_vars *v)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	y = -1;
	i = 0;
	black_screen(v);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			v->x_val = ((x - WIDTH / 2.0) / v->zoom) + v->vertical_swift;
			v->y_val = ((y - HEIGHT / 2.0) / v->zoom) + v->horizontal_swift;
			i = func_brain_ship(v, x, y);
			color_change(v, i);
			if ((v->x_val * v->x_val + v->y_val * v->y_val) < 4)
				put_pixel_in_img(v, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(v, x, y, create_trgb(0, v->c1, v->c2, v->c3));
		}
	}
	mlx_put_image_to_window(v->img.mlx, v->img.win, v->img.image, 0, 0);
}

int	func_brain_ship(t_vars *vars, int x, int y)
{
	int		i;
	double	temp;

	i = 0;
	while (i < MAX_ITER && vars->x_val * vars->x_val + vars->y_val
		* vars->y_val < 4)
	{
		temp = vars->x_val;
		vars->x_val = fabs(vars->x_val * vars->x_val - vars->y_val * vars->y_val
				+ vars->selected_r);
		vars->y_val = fabs(2 * temp * vars->y_val) + vars->selected_i;
		i++;
	}
	return (i);
}
