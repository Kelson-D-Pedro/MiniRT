/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:52 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/30 13:51:01 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

int	main(int argc, char *argv[])
{
	t_scene	rt;

	ft_bzero(&rt, sizeof(t_scene));
	if (its_alright_to_start(&rt, argv, argc))
	{
		free_matrix((void **)rt.map);
		return (1);
	}
	fill_elements(&rt);
	init_3d_camera(&rt);
	init_mlx_win(&rt);
	init_mlx_image(&rt);
	put_map(&rt);
	mlx_put_image_to_window(rt.mini_lx.mlx, rt.mini_lx.win, rt.mini_lx.img, 0,
		0);
	mlx_mouse_hook(rt.mini_lx.win, select_obj, &rt);
	mlx_key_hook(rt.mini_lx.win, hooks, &rt);
	mlx_hook(rt.mini_lx.win, 17, 0, close_window, &rt);
	mlx_loop(rt.mini_lx.mlx);
	return (0);
}
