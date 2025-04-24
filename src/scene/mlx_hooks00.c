/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:44:35 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 13:09:01 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/miniRT.h"

int     make_moves(int key, t_scene *rt)
{
    int i;

    i = 0;
    if (key == XK_Left)
    {
        rt->light.pos.z -=1;
        i = 1;
    }
    else if (key == XK_Right)
    {
        rt->light.pos.z +=1;
        i = 1;
    }
    else if (key == XK_Up)
    {
        rt->sphere[0].pos.y +=0.3;
        rt->sphere[0].pos.x -=0.3;
        rt->sphere[0].pos.z -=1;
        i = 1;
    }
     else if (key == XK_Down)
    {
        rt->sphere[0].pos.y -=1;
        i = 1;
    }
    if (i)
    {
        put_map(rt);
        mlx_put_image_to_window(rt->mini_lx.mlx, rt->mini_lx.win, rt->mini_lx.img, 0,
            0);
    }
    return (0);
}

int     hooks(int key, void *arg)
{
    t_scene     *rt;

    rt = (t_scene *)arg;
    if (key == XK_Escape)
        handle_keypress(key, rt);
    else
        make_moves(key, rt);
    /* printf("%c\n", rt->active_obj.type); */
    return (0);
    
}
