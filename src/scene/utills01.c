/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:24:28 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 14:51:54 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void set_active_obj(t_scene *rt, t_pair *obj, char type)
{
    if (obj == NULL)
    {
        rt->active_obj.type = type;
        return ;
    }
    rt->active_obj.index = obj->index;
    rt->active_obj.type = type;
    
}

int    select_obj(int key, int x, int y, void *arg)
{
    t_ray   ray;
    t_scene *rt;
    t_pair  obj;

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
    return (0);
}