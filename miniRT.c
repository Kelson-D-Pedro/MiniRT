/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:52 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/04 15:10:01 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

int	main(int argc, char *argv[])
{
	t_elements	rt;

	if (its_alright_to_start(&rt, argv, argc))
		return (1);
	fill_elements(&rt);
	init_mlx_win(&rt);
	init_mlx_win(&rt);
	mlx_loop(rt.mini_lx.mlx);
	free_matrix((void **)rt.map);
	return (0);
}
