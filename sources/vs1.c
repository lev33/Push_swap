/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:17:23 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:23:45 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "mlx.h"

static void			put_pixel(t_vs *vs, int x, int y, int color)
{
	int		i;

	i = (x * vs->bits_per_pixel / 8) + (y * vs->size_line);
	vs->data_addr[i] = color;
	vs->data_addr[++i] = color >> 8;
	vs->data_addr[++i] = color >> 16;
}

static void			draw_rectangle(t_vs *vs, t_rectangle *rectangle)
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;

	x = rectangle->x_start;
	color = (x < (MENU_WIDTH + (WIDTH - MENU_WIDTH) / 4)) ? GREEN : YELLOW;
	width = rectangle->x_end;
	height = rectangle->y_end;
	while (x < width)
	{
		y = rectangle->y_start;
		while (y < height)
		{
			put_pixel(vs, x, y, color);
			y++;
		}
		x++;
	}
}

static void			draw_stack(t_vs *vs, t_stack *stack, int x_start)
{
	size_t		i;
	t_elem		*current;
	t_rectangle	*rectangle;
	int			len;

	i = vs->max_size - stack->size;
	current = stack->head;
	while (i < vs->max_size)
	{
		if (!(rectangle = (t_rectangle *)ft_memalloc(sizeof(t_rectangle))))
			throw("Error");
		len = (current->index + 1) * vs->width_pix;
		rectangle->x_start = x_start - len / 2;
		rectangle->x_end = x_start + len / 2;
		rectangle->y_start = i * vs->height_pix;
		rectangle->y_end = (i + 1) * vs->height_pix;
		draw_rectangle(vs, rectangle);
		free(rectangle);
		i++;
		current = current->next;
	}
}

static void			print_menu(t_vs *vs)
{
	int			y;
	void		*mlx;
	void		*win;

	y = 0;
	mlx = vs->mlx;
	win = vs->win;
	mlx_string_put(mlx, win, 25, y += 50, GREEN, "Stack a");
	mlx_string_put(mlx, win, 145, y, YELLOW, "Stack b");
	mlx_string_put(mlx, win, 55, y += 45, TEXT_COLOR, "Instructions:");
	mlx_string_put(mlx, win, 35, y += 30, TEXT_COLOR, "pb            pa");
	mlx_string_put(mlx, win, 35, y += 30, TEXT_COLOR, "sa     ss     sb");
	mlx_string_put(mlx, win, 35, y += 30, TEXT_COLOR, "ra     rr     rb");
	mlx_string_put(mlx, win, 30, y += 30, TEXT_COLOR, "rra    rrr    rrb");
}

void				draw(t_vs *vs)
{
	int	*image;
	int	i;

	ft_bzero(vs->data_addr, WIDTH * HEIGHT * (vs->bits_per_pixel / 8));
	image = (int *)(vs->data_addr);
	i = -1;
	while (++i < HEIGHT * WIDTH)
		image[i] = (i % WIDTH < MENU_WIDTH) ? GREY_1 : GREY_2;
	draw_stack(vs, vs->d->a, MENU_WIDTH + (WIDTH - MENU_WIDTH) / 4);
	draw_stack(vs, vs->d->b, MENU_WIDTH + 3 * (WIDTH - MENU_WIDTH) / 4);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 0, 0);
	print_menu(vs);
	mlx_do_sync(vs->mlx);
}
