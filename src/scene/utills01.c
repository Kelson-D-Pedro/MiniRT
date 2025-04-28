/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:24:28 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 13:30:42 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	set_active_obj(t_scene *rt, t_pair *obj, char type)
{
	if (obj == NULL)
	{
		rt->active_obj.type = type;
		return ;
	}
	rt->active_obj.index = obj->index;
	rt->active_obj.type = type;
}

static void	unknow(int key, t_scene *rt)
{
	int	i;

	i = 0;
	if (rt->active_obj.type == 's' && key == 4)
		sphere_size_up_down(&rt->sphere[rt->active_obj.index], '+', 0.3, &i);
	else if (rt->active_obj.type == 's' && key == 5)
		sphere_size_up_down(&rt->sphere[rt->active_obj.index], '-', 0.3, &i);
	else if (rt->active_obj.type == 'c' && key == 4)
		cylinder_size_up_down(&rt->cylinder[rt->active_obj.index], '+', 0.3,
			&i);
	else if (rt->active_obj.type == 'c' && key == 5)
		cylinder_size_up_down(&rt->cylinder[rt->active_obj.index], '-', 0.3,
			&i);
	if (i)
	{
		put_map(rt);
		mlx_put_image_to_window(rt->mini_lx.mlx, rt->mini_lx.win,
			rt->mini_lx.img, 0, 0);
	}
}

int	select_obj(int key, int x, int y, void *arg)
{
	t_ray	ray;
	t_scene	*rt;
	t_pair	obj;

	rt = (t_scene *)arg;
	ray = send_rays(rt, x, y);
	obj = intersect_objs(rt, &ray);
	if (key == 1)
	{
		if (obj.type == 's')
			set_active_obj(rt, &obj, 's');
		else if (obj.type == 'p')
			set_active_obj(rt, &obj, 'p');
		else if (obj.type == 'c')
			set_active_obj(rt, &obj, 'c');
	}
	else if (key == 3)
		set_active_obj(rt, NULL, 'C');
	else if (key == 2)
		set_active_obj(rt, NULL, 'L');
	else if (key == 4 || key == 5)
		unknow(key, rt);
	return (0);
}
