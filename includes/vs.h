/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:05:42 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:05:48 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_H

# define VS_H

# include "push_swap.h"

# define HEIGHT		1000
# define WIDTH		1850
# define MENU_WIDTH 250

# define GREY_1		0x333333
# define GREY_2		0x222222
# define YELLOW		0xF0D347
# define TEXT_COLOR 0xFFFFFF
# define GREEN      0x008000
# define RED        0xFF0000

typedef struct		s_vs
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width_pix;
	int				height_pix;
	t_data			*d;
	size_t			max_size;
}					t_vs;

typedef struct		s_rectangle
{
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
}					t_rectangle;

void				draw(t_vs *vs);

#endif
