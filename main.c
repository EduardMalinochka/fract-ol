/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:29 by elukutin          #+#    #+#             */
/*   Updated: 2023/03/01 14:48:38 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fract(char **str, t_vars *vars)
{
	if (ft_strncmp(str[1], "Julia", 6) == 0)
	{
		vars->selected_r = vars->julia_r[0];
		vars->selected_i = vars->julia_i[0];
		vars->fig = 'J';
		draw_julia(vars);
	}
	else if (ft_strncmp(str[1], "Mandelbrot", 11) == 0)
	{
		vars->fig = 'M';
		draw_mandel(vars);
	}
	else
	{
		vars->fig = 'B';
		vars->selected_r = vars->julia_r[0];
		vars->selected_i = vars->julia_i[0];
		draw_brain_ship(vars);
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		if (ft_strncmp(av[1], "Mandelbrot", 11) == 0 || ft_strncmp(av[1],
				"Julia", 6) == 0 || ft_strncmp(av[1], "Brain", 6) == 0)
		{
			init_vars(&vars);
			set_fract(av, &vars);
			mlx_hook(vars.img.win, 4, 0, zoom, &vars);
			mlx_hook(vars.img.win, 5, 0, zoom, &vars);
			mlx_key_hook(vars.img.win, key, &vars);
			mlx_loop(vars.img.mlx);
		}
		else
			quit(&vars);
	}
	else
		quit(&vars);
}
