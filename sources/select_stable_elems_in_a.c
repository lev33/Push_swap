/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_stable_elems_in_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:22:55 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:22:59 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	set_stable_v1(t_elem *head_2)
{
	ssize_t			index;
	size_t			count;
	t_elem			*current;

	count = 1;
	if (head_2)
	{
		index = head_2->index;
		head_2->stable = true;
		current = head_2->next;
		while (current != head_2)
		{
			if (current->index == index + 1)
			{
				count++;
				index++;
				current->stable = true;
			}
			else
				current->stable = false;
			current = current->next;
		}
	}
	return (count);
}

size_t	set_stable_v2(t_elem *head_2)
{
	ssize_t			index;
	size_t			count;
	t_elem			*current;

	count = 1;
	if (head_2)
	{
		index = head_2->index;
		head_2->stable = true;
		current = head_2->next;
		while (current != head_2)
		{
			if (current->index > index)
			{
				count++;
				index = current->index;
				current->stable = true;
			}
			else
				current->stable = false;
			current = current->next;
		}
	}
	return (count);
}

void	select_stable_elems_in_a(t_data *d, size_t (*set_stable)(t_elem *))
{
	size_t			i;
	size_t			current_count;
	t_elem			*current;

	if (d->a)
	{
		i = 0;
		current = d->a->head;
		while (i++ < d->a->size)
		{
			current_count = set_stable(current);
			if (current_count > d->a->count)
			{
				d->a->head_2 = current;
				d->a->count = current_count;
			}
			else if (current_count == d->a->count &&
					(!d->a->head_2 || current->number < d->a->head_2->number))
				d->a->head_2 = current;
			current = current->next;
		}
	}
	set_stable(d->a->head_2);
}
