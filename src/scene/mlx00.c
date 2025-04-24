/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:35:47 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 11:41:07 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	init_mlx_win(t_scene *rt)
{
	rt->mini_lx.mlx = mlx_init();
	if (!rt->mini_lx.mlx)
		exit(1);
	rt->mini_lx.win = mlx_new_window(rt->mini_lx.mlx, 1920, 1080, "C DE CUCESSO");
	if (!rt->mini_lx.win)
	{
		mlx_destroy_display(rt->mini_lx.mlx);
		free(rt->mini_lx.mlx);
		exit(1);
	}
}

void	init_mlx_image(t_scene *rt)
{
	rt->mini_lx.img = mlx_new_image(rt->mini_lx.mlx, 1920, 1080);
	if (!rt->mini_lx.img)
	{
		mlx_destroy_window(rt->mini_lx.mlx, rt->mini_lx.win);
		free(rt->mini_lx.mlx);
		exit(1);
	}
	rt->mini_lx.addr = mlx_get_data_addr(rt->mini_lx.img, &rt->mini_lx.bpp,
			&rt->mini_lx.line_length, &rt->mini_lx.endian);
	if (!rt->mini_lx.addr)
	{
		mlx_destroy_image(rt->mini_lx.mlx, rt->mini_lx.img);
		mlx_destroy_window(rt->mini_lx.mlx, rt->mini_lx.win);
		free(rt->mini_lx.mlx);
		exit(1);
	}
}

int	close_window(t_scene *rt)
{
	mlx_destroy_window(rt->mini_lx.mlx, rt->mini_lx.win);
	free(rt->mini_lx.mlx);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_scene *rt)
{
	if (keycode == XK_Escape)
		close_window(rt);
	return (0);
}

void	my_pixel_put(t_scene *rt, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = rt->mini_lx.addr + (y * rt->mini_lx.line_length + x * (rt->mini_lx.bpp
				/ 8));
	*(unsigned int *)dst = color;
}
