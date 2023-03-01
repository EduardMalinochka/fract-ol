/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:42 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/24 15:58:34 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key(int keycode, t_vars *vars)
{
	if (keycode >= 123 && keycode <= 126)
		move(keycode, vars);
	if (keycode == 0 || keycode == 2)
		julia_swap(keycode, vars);
	if (keycode == 53)
		close_program(keycode, vars);
	if (keycode == 15 || keycode == 257)
		reinit_vars(vars);
	if (keycode == 8)
		colorful_fract(vars);
	return (1);
}

void	colorful_fract(t_vars *vars)
{
	if (++vars->color > 5)
		vars->color = 0;
	choose_frac(vars);
}

void	move(int keycode, t_vars *vars)
{
	if (keycode == 123)
	{
		vars->vertical_swift -= 100 / vars->zoom;
		choose_frac(vars);
	}
	else if (keycode == 124)
	{
		vars->vertical_swift += 100 / vars->zoom;
		choose_frac(vars);
	}
	else if (keycode == 125)
	{
		vars->horizontal_swift += 100 / vars->zoom;
		choose_frac(vars);
	}
	else if (keycode == 126)
	{
		vars->horizontal_swift -= 100 / vars->zoom;
		choose_frac(vars);
	}
}

void	julia_swap(int keycode, t_vars *vars)
{
	static int	index;

	if (keycode == 2)
	{
		if (++index > 8)
			index = 0;
		vars->selected_r = vars->julia_r[index];
		vars->selected_i = vars->julia_i[index];
		choose_frac(vars);
	}
	else if (keycode == 0)
	{
		if (--index < 0)
			index = 8;
		vars->selected_r = vars->julia_r[index];
		vars->selected_i = vars->julia_i[index];
		choose_frac(vars);
	}
}

int	zoom(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 5)
	{
		vars->vertical_swift += ((x - (WIDTH / 2)) / (vars->zoom * 3));
		vars->horizontal_swift += ((y - (HEIGHT / 2)) / (vars->zoom * 3));
		vars->zoom *= 1.5;
		choose_frac(vars);
	}
	else if (keycode == 4)
	{
		vars->vertical_swift -= ((x - (WIDTH / 2)) / (vars->zoom * 3));
		vars->horizontal_swift -= ((y - (HEIGHT / 2)) / (vars->zoom * 3));
		vars->zoom /= 1.5;
		choose_frac(vars);
	}
	return (0);
}
