/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:44:35 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 13:29:07 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static void	moves_auxiliar(int key, t_scene *rt, t_vector *dir, int i)
{
	if (dir)
	{
		if (key == XK_q)
			x_axis_rotation(dir, 0.785398163, &i);
		else if (key == XK_w)
			x_axis_rotation(dir, -0.785398163, &i);
		else if (key == XK_a)
			y_axis_rotation(dir, 0.785398163, &i);
		else if (key == XK_s)
			y_axis_rotation(dir, -0.785398163, &i);
		else if (key == XK_z)
			z_axis_rotation(dir, 0.785398163, &i);
		else if (key == XK_x)
			z_axis_rotation(dir, -0.785398163, &i);
	}
	if (i)
	{
		put_map(rt);
		mlx_put_image_to_window(rt->mini_lx.mlx, rt->mini_lx.win,
			rt->mini_lx.img, 0, 0);
	}
}

int	moves(int key, t_vector *pos, t_scene *rt, t_vector *dir)
{
	int	i;

	i = 0;
	if (key == XK_Left)
		x_axis_translate(pos, 0.5, '-', &i);
	else if (key == XK_Right)
		x_axis_translate(pos, 0.5, '+', &i);
	else if (key == XK_Up)
		y_axis_translate(pos, 0.5, '+', &i);
	else if (key == XK_Down)
		y_axis_translate(pos, 0.5, '-', &i);
	else if (key == XK_n)
		z_axis_translate(pos, 0.5, '+', &i);
	else if (key == XK_m)
		z_axis_translate(pos, 0.5, '-', &i);
	moves_auxiliar(key, rt, dir, i);
	if (i)
	{
		put_map(rt);
		mlx_put_image_to_window(rt->mini_lx.mlx, rt->mini_lx.win,
			rt->mini_lx.img, 0, 0);
	}
	return (0);
}

static void	transformations(int key, t_scene *rt)
{
	if (rt->active_obj.type == 's')
		moves(key, &rt->sphere[rt->active_obj.index].pos, rt, NULL);
	else if (rt->active_obj.type == 'p')
		moves(key, &rt->plane[rt->active_obj.index].pos, rt,
			&rt->plane[rt->active_obj.index].dir);
	else if (rt->active_obj.type == 'c')
		moves(key, &rt->cylinder[rt->active_obj.index].pos, rt,
			&rt->cylinder[rt->active_obj.index].dir);
	else if (rt->active_obj.type == 'C')
		moves(key, &rt->camera.pos, rt, &rt->camera.dir);
	else if (rt->active_obj.type == 'L')
		moves(key, &rt->light.pos, rt, NULL);
	if (key == XK_space)
		set_active_obj(rt, NULL, 'N');
}

int	hooks(int key, void *arg)
{
	t_scene	*rt;

	rt = (t_scene *)arg;
	if (key == XK_Escape)
		handle_keypress(key, rt);
	else
		transformations(key, rt);
	return (0);
}
