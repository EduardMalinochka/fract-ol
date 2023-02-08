/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:50 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/08 17:50:15 by elukutin         ###   ########.fr       */
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

int	closee(int keycode, t_vars *vars)
{
	exit(EXIT_SUCCESS);
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

void	swtch_draw(t_vars *vars)
{
	if (vars->swtch == 0)
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
		vars->swtch = 0;
		draw(vars);
	}
	else if (ft_strncmp(str[1], "Mandelbrot", 11) == 0)
	{
		vars->swtch = 1;
		draw2(vars);
	}
}
