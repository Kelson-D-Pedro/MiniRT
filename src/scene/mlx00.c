/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:35:47 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/03 16:00:32 by kpedro           ###   ########.fr       */
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
	mlx_hook(rt->mini_lx.win, 17, 0, close_window, rt);
	mlx_key_hook(rt->mini_lx.win, handle_keypress, rt);
}

void	init_mlx_image(t_elements *rt)
{
    rt->mini_lx.img = mlx_new_image(rt->mini_lx.mlx, 1920, 1080);
    if (!rt->mini_lx.img)
    {
        mlx_destroy_window(rt->mini_lx.mlx, rt->mini_lx.win);
        free(rt->mini_lx.mlx);
        exit(1);
    }
    rt->mini_lx.addr = mlx_get_data_addr(rt->mini_lx.img, &rt->mini_lx.bits_per_pixel,
                                         &rt->mini_lx.line_length, &rt->mini_lx.endian);
    if (!rt->mini_lx.addr)
    {
        mlx_destroy_image(rt->mini_lx.mlx, rt->mini_lx.img);
        mlx_destroy_window(rt->mini_lx.mlx, rt->mini_lx.win);
        free(rt->mini_lx.mlx);
        exit(1);
    }
}

int	close_window(t_elements *rt)
{
	mlx_destroy_window(rt->mini_lx.mlx, rt->mini_lx.win);
	free(rt->mini_lx.mlx);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_elements *rt)
{
	if (keycode == 65307)
		close_window(rt);
	return (0);
}
