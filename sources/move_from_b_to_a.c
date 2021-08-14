/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:15:57 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/08/09 22:32:52 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			find_ra_size(t_stack *a, int index, size_t *ra_size)
{
	t_elem	*current;

	if (a->head)
	{
		current = a->head;
		while (current->index != index)
		{
			(*ra_size)++;
			current = current->next;
		}
	}
}

static void			set_rotation(size_t size, t_rotation tmp,
		t_rotation *rotation)
{
	if (!rotation->is_set || size < rotation->size)
	{
		rotation->a_elem = tmp.a_elem;
		rotation->b_elem = tmp.b_elem;
		rotation->a_direction = tmp.a_direction;
		rotation->b_direction = tmp.b_direction;
		rotation->size = size;
		rotation->is_set = true;
	}
}

static void			get_rotation(t_data *d, t_elem *b_elem,
		t_rotation *rotation, size_t i)
{
	t_rotation		tmp;
	size_t			ra_size;
	size_t			rra_size;
	size_t			rb_size;
	size_t			rrb_size;

	ra_size = 0;
	rb_size = i;
	rrb_size = i ? d->b->size - i : 0;
	tmp.a_elem = find_tmp_head(d->a, b_elem->index);
	tmp.b_elem = b_elem;
	find_ra_size(d->a, tmp.a_elem->index, &ra_size);
	rra_size = ra_size ? d->a->size - ra_size : 0;
	tmp.a_direction = 1;
	tmp.b_direction = 1;
	set_rotation((ra_size > rb_size) ? ra_size : rb_size, tmp, rotation);
	tmp.a_direction = -1;
	set_rotation(rra_size + rb_size, tmp, rotation);
	tmp.b_direction = -1;
	set_rotation((rra_size > rrb_size) ? rra_size : rrb_size, tmp, rotation);
	tmp.a_direction = 1;
	set_rotation(ra_size + rrb_size, tmp, rotation);
}

static void			rotate(t_data *d, t_rotation *rotation)
{
	while (rotation->a_elem != d->a->head
			|| rotation->b_elem != d->b->head)
	{
		if (rotation->a_direction == rotation->b_direction
				&& rotation->a_elem != d->a->head
				&& rotation->b_elem != d->b->head)
			(rotation->a_direction == 1) ? rr(d, "rr") : rrr(d, "rrr");
		else if (rotation->a_elem != d->a->head)
			(rotation->a_direction == 1) ? ra(d, "ra") : rra(d, "rra");
		else if (rotation->b_elem != d->b->head)
			(rotation->b_direction == 1) ? rb(d, "rb") : rrb(d, "rrb");
	}
}

void				move_from_b_to_a(t_data *d)
{
	t_rotation	*rotation;
	size_t		i;
	t_elem		*current;

	if (!(rotation = (t_rotation *)ft_memalloc(sizeof(t_rotation))))
		throw("Error");
	while (d->b->size)
	{
		rotation->is_set = false;
		i = 0;
		current = d->b->head;
		while (i++ < d->b->size)
		{
			get_rotation(d, current, rotation, i - 1);
			current = current->next;
		}
		rotate(d, rotation);
		pa(d, "pa");
	}
	free(rotation);
}
