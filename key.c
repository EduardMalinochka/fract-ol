/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:42 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/24 12:29:44 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key(int keycode, t_vars *vars)
{
	static int	index;

	if (keycode >= 123 && keycode <= 126)
		move(keycode, vars);
	if (keycode == 12)
	{
		if (++index > 8)
			index = 0;
		vars->selected_r = vars->julia_r[index];
		vars->selected_i = vars->julia_i[index];
		choose_draw(vars);
	}
	else if (keycode == 53)
		quit(vars);
	else if (keycode == 8)
		colorful_fract(vars);
	return (1);
}

void	colorful_fract(t_vars *vars)
{
	if (++vars->color > 5)
		vars->color = 0;
	choose_draw(vars);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == 123)
	{
		vars->vertical_swift -= 100 / vars->zoom;
		choose_draw(vars);
	}
	else if (keycode == 124)
	{
		vars->vertical_swift += 100 / vars->zoom;
		choose_draw(vars);
	}
	else if (keycode == 125)
	{
		vars->horizontal_swift += 100 / vars->zoom;
		choose_draw(vars);
	}
	else if (keycode == 126)
	{
		vars->horizontal_swift -= 100 / vars->zoom;
		choose_draw(vars);
	}
	else if (keycode == 53)
		close_program(keycode, vars);
	return (1);
}
