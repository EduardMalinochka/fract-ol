/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:29 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/24 15:58:14 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		if (ft_strncmp(av[1], "Mandelbrot", 11) == 0 || ft_strncmp(av[1],
				"Julia", 6) == 0)
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
