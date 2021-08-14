/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:15:41 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:15:49 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_unstable(t_stack *a)
{
	size_t		i;
	t_elem		*current;

	if (a)
	{
		i = 0;
		current = a->head;
		while (i++ < a->size)
		{
			if (!current->stable)
				return (true);
			current = current->next;
		}
	}
	return (false);
}

static t_bool	needs_sa(t_data *d,
		size_t (*set_stable)(t_elem *))
{
	size_t	current_count;

	if (d->a && d->a->size >= 2)
	{
		sa(d, NULL);
		current_count = set_stable(d->a->head_2);
		sa(d, NULL);
		set_stable(d->a->head_2);
		if (current_count > d->a->count)
			return (true);
	}
	return (false);
}

void			move_from_a_to_b(t_data *d,
		size_t (*set_stable)(t_elem *))
{
	while (is_unstable(d->a))
	{
		if (needs_sa(d, set_stable))
		{
			sa(d, "sa");
			d->a->count = set_stable(d->a->head_2);
		}
		else if (d->a->head->stable == false)
			pb(d, "pb");
		else
			ra(d, "ra");
	}
}
