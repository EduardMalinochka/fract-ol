/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:29 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/18 20:49:18 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 5)
	{
		vars->vertical_swift += ((x - (WIDTH / 2)) / (vars->zoom * 3));
		vars->horizontal_swift += ((y - (HEIGHT / 2)) / (vars->zoom * 3));
		vars->zoom *= 1.5;
		choose_draw(vars);
	}
	else if (keycode == 4)
	{
		vars->vertical_swift -= ((x - (WIDTH / 2)) / (vars->zoom * 3));
		vars->horizontal_swift -= ((y - (HEIGHT / 2)) / (vars->zoom * 3));
		vars->zoom *= 2.0 / 3.0;
		choose_draw(vars);
	}
	return (0);
}

int	main(int ac, char**av)
{
	t_vars	vars;

	if (ac == 2)
	{
		if (ft_strncmp(av[1], "Mandelbrot", 11) == 0 || ft_strncmp(av[1], "Julia", 6) == 0)
		{
			init_vars(&vars);
			set_fract(av, &vars);
			mlx_hook(vars.img.win, 4, 0, zoom, &vars);
			mlx_hook(vars.img.win, 5, 0, zoom, &vars);
			mlx_hook(vars.img.win, 2, 0, close_program, &vars);
			mlx_key_hook(vars.img.win, key, &vars);
			mlx_loop(vars.img.mlx);
		}
		else
			quit(&vars);
	}
	else
		quit(&vars);
}
