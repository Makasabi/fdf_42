/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:22:43 by mrony             #+#    #+#             */
/*   Updated: 2023/05/19 17:26:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pix_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = fdf->bpp - 8;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
		while (i >= 0)
		{
			if (fdf->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (fdf->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

void	ft_mlx(t_build *build)
{
	t_fdf	fdf;

	fdf = ft_fdf_init(fdf, build);
	fdf.mlx_ptr = mlx_init();
	if (fdf.mlx_ptr == NULL)
		ft_exit_fail_fdfinit(fdf.build, MLX_ERROR);
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, build->map_name);
	if (fdf.win_ptr == NULL)
		ft_exit_fail_winptr(fdf.build, &fdf, WINDOW_ERROR);
	fdf.mlx_img = mlx_new_image(fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf.addr = mlx_get_data_addr(fdf.mlx_img, &fdf.bpp,
			&fdf.line_len, &fdf.endian);
	mlx_loop_hook(fdf.mlx_ptr, &ft_render, &fdf);
	mlx_hook(fdf.win_ptr, ButtonPress, ButtonPressMask, ft_handle_mouse, &fdf);
	mlx_hook(fdf.win_ptr, KeyPress, KeyPressMask, ft_handle_keypress, &fdf);
	mlx_hook(fdf.win_ptr, ClientMessage, StructureNotifyMask,
		&ft_handle_destroy_window, &fdf);
	mlx_loop(fdf.mlx_ptr);
	mlx_destroy_image(fdf.mlx_ptr, fdf.mlx_img);
	mlx_destroy_display(fdf.mlx_ptr);
	free(fdf.mlx_ptr);
	ft_end_prog(fdf.map, fdf.map_height, fdf.build->map_name);
}
