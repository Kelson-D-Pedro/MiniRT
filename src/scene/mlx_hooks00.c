/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:44:35 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 14:53:39 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/miniRT.h"

int     make_moves(int key, t_vector *pos, t_scene *rt)
{
    int i;

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
    if (i)
    {
        put_map(rt);
        mlx_put_image_to_window(rt->mini_lx.mlx, rt->mini_lx.win, rt->mini_lx.img, 0,
            0);
    }
    return (0);
}

static  void    transformations(int key, t_scene *rt)
{
    if (rt->active_obj.type == 's')
        make_moves(key, &rt->sphere[rt->active_obj.index].pos, rt);
    else if (rt->active_obj.type == 'p')
        make_moves(key, &rt->plane[rt->active_obj.index].pos, rt);
    else if (rt->active_obj.type == 'c')
        make_moves(key, &rt->cylinder[rt->active_obj.index].pos, rt);
    else if (rt->active_obj.type =='C')
        make_moves(key, &rt->camera.pos, rt);
    else if (rt->active_obj.type == 'L')
        make_moves(key, &rt->light.pos, rt);
    if (key == XK_space)
        set_active_obj(rt, NULL, 'N');
}

int     hooks(int key, void *arg)
{
    t_scene     *rt;

    rt = (t_scene *)arg;
    if (key == XK_Escape)
        handle_keypress(key, rt);
    else
        transformations(key, rt);
    return (0);
    
}
