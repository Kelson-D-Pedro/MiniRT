/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:52 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/24 09:51:19 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

int	main(int argc, char *argv[])
{
	t_scene	rt;

	if (its_alright_to_start(&rt, argv, argc))
		return (1);
	fill_elements(&rt);
	init_3d_camera(&rt);
	init_mlx_win(&rt);
	init_mlx_image(&rt);
	put_map(&rt);
	mlx_put_image_to_window(rt.mini_lx.mlx, rt.mini_lx.win, rt.mini_lx.img, 0,
		0);
	mlx_loop(rt.mini_lx.mlx);
	free_matrix((void **)rt.map);
	return (0);
}
