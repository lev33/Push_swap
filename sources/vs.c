/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:16:57 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:17:16 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vs.h"
#include "get_next_line.h"

int						win_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static void				run_minilibx(t_vs *vs)
{
	size_t			size;
	char			*line;

	if (!(vs->mlx = mlx_init()))
		throw("Error");
	if (!(vs->win = mlx_new_window(vs->mlx, WIDTH, HEIGHT, "Push Swap")))
		throw("Error");
	if (!(vs->img = mlx_new_image(vs->mlx, WIDTH, HEIGHT)))
		throw("Error");
	vs->data_addr = mlx_get_data_addr(vs->img, &(vs->bits_per_pixel),
			&(vs->size_line), &(vs->endian));
	vs->width_pix = (WIDTH - MENU_WIDTH) / 2 / vs->d->a->size;
	vs->height_pix = HEIGHT / vs->d->a->size;
	vs->max_size = vs->d->a->size;
	mlx_hook(vs->win, 17, 0, win_close, vs);
	draw(vs);
	while ((size = get_next_line(0, &line)) > 0)
	{
		execute_instruction(vs->d, line);
		free(line);
		draw(vs);
	}
	mlx_loop(vs->mlx);
}

int						main(int argc, char **argv)
{
	t_vs	*vs;

	if (argc < 2)
		ft_putendl("Usage: ./vs <numbers>");
	else
	{
		if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
			throw("Error");
		vs->d = get_data(argc, argv);
		if (vs->d->a->size <= HEIGHT / 4)
			run_minilibx(vs);
		else
			ft_putendl("Maximum 250 numbers");
	}
	return (0);
}
