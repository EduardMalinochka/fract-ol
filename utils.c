/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:50 by elukutin          #+#    #+#             */
/*   Updated: 2023/03/01 14:55:30 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	swap_int(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	quit(t_vars *vars)
{
	ft_putendl_fd("Availiable fractals are:", 1);
	write(1, "\n", 1);
	ft_putendl_fd("Julia/Mandelbrot/Brain", 1);
	write(1, "\n", 1);
	ft_putendl_fd("Make sure you've typed correctly", 1);
	write(1, "\n", 1);
	ft_putendl_fd("Zoom with the mouse, move with the arrows", 1);
	write(1, "\n", 1);
	ft_putendl_fd("C button allows you to shift the colors", 1);
	write(1, "\n", 1);
	ft_putendl_fd("R button will reverse the zoom to init point", 1);
	write(1, "\n", 1);
	ft_putendl_fd("You can switch between Julia Sets via A and D buttons", 1);
	write(1, "\n", 1);
	ft_putendl_fd("Press ESC to quit", 1);
	exit(0);
	return (0);
}

int	close_program(int key, t_vars *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->img.mlx, vars->img.win);
		exit(0);
	}
	return (0);
}

void	choose_frac(t_vars *vars)
{
	if (vars->fig == 'J')
		draw_julia(vars);
	else if (vars->fig == 'M')
		draw_mandel(vars);
	else
		draw_brain_ship(vars);
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
