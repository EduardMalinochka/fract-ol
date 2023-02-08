/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:42 by elukutin          #+#    #+#             */
/*   Updated: 2023/02/08 15:15:11 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key(int keycode, t_vars *vars)
{
	static int	index;

	if (keycode >= 123 && keycode <= 126)
		move(keycode, vars);
	if (keycode == 38)
	{
		if (++index > 8)
			index = 0;
		vars->selected_r = vars->julia_r[index];
		vars->selected_i = vars->julia_i[index];
		swtch_draw(vars);
	}
	else if (keycode == 53)
		closee(keycode, vars);
	else if (keycode == 8)
		colorful_fract(vars);
	return (1);
}

void	colorful_fract(t_vars *vars)
{
	if (++vars->color > 5)
		vars->color = 0;
	swtch_draw(vars);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == 123)
	{
		vars->vertical_swift -= 70 / vars->zoom;
		swtch_draw(vars);
	}
	else if (keycode == 124)
	{
		vars->vertical_swift += 70 / vars->zoom;
		swtch_draw(vars);
	}
	else if (keycode == 125)
	{
		vars->horizontal_swift += 70 / vars->zoom;
		swtch_draw(vars);
	}
	else if (keycode == 126)
	{
		vars->horizontal_swift -= 70 / vars->zoom;
		swtch_draw(vars);
	}
	else if (keycode == 53)
		closee(keycode, vars);
	return (1);
}
