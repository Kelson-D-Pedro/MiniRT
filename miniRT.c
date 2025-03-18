/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:52 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/18 12:39:08 by kpedro           ###   ########.fr       */
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
	//init_mlx_win(&rt);
	put_map(&rt);
	//mlx_loop(rt.mini_lx.mlx);
	free_matrix((void **)rt.map);
	return (0);
}
