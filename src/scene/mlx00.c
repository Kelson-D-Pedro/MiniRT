/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:35:47 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/12 13:37:29 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	init_mlx_win(t_elements *rt)
{
	rt->mini_lx.mlx = mlx_init();
	if (!rt->mini_lx.mlx)
		exit(1);
	rt->mini_lx.win = mlx_new_window(rt->mini_lx.mlx, 1920, 1080, "teste");
	if (!rt->mini_lx.win)
	{
		mlx_destroy_display(rt->mini_lx.mlx);
		free(rt->mini_lx.mlx);
		exit(1);
	}
}
