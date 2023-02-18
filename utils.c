/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:50 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/18 20:16:27 by elukutin         ###   ########.fr       */
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

int	quit(int keycode, t_vars *vars)
{
	write(1, "[Mandelbort],[Julia]\n", 21);
	exit(0);
	return (0);
}
int	close_program(int key, t_vars *vars) //don't forget to repair this function
{
	if (key == 53)
	{
		mlx_destroy_window(vars->img.mlx, vars->img.win);
		exit(0);
	}
	else if (key == 15 || key == 257)
	{
		draw(vars); // change this
		write(1, "r", 1);
	}
	return (0);
}

void	choose_draw(t_vars *vars)
{
	if (vars->fig == 'J')
		draw(vars);
	else
		draw2(vars);
}

void	set_fract(char **str, t_vars *vars)
{
	if (ft_strncmp(str[1], "Julia", 6) == 0)
	{
		vars->selected_r = vars->julia_r[0];
		vars->selected_i = vars->julia_i[0];
		vars->fig = 'J';
		draw(vars);
	}
	else if (ft_strncmp(str[1], "Mandelbrot", 11) == 0)
	{
		vars->fig = 'M';
		draw2(vars);
	}
}
