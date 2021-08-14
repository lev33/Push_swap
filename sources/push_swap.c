/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:21:47 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:21:54 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_instructions(t_instructions *v)
{
	t_inst		*current;

	current = v->head;
	while (current)
	{
		ft_putendl(current->instruction);
		current = current->next;
	}
}

static void			align_a(t_data *d)
{
	t_elem			*current;
	size_t			ra_size;

	if (d->a && d->a->head)
	{
		ra_size = 0;
		current = d->a->head;
		while (current->index)
		{
			ra_size++;
			current = current->next;
		}
		while (d->a->head->index)
			(ra_size * 2 < d->a->size) ? ra(d, "ra") : rra(d, "rra");
	}
}

static void			get_instructions(int argc, char **argv,
		t_instructions *v, size_t (*set_stable)(t_elem *))
{
	t_data			*d;

	d = get_data(argc, argv);
	d->c = v;
	select_stable_elems_in_a(d, set_stable);
	move_from_a_to_b(d, set_stable);
	move_from_b_to_a(d);
	align_a(d);
	free_stack(d->a);
	free_stack(d->b);
	free(d);
}

static void			free_instructions(t_instructions *v)
{
	t_inst *current;
	t_inst *delete;

	current = v->head;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->instruction);
		free(delete);
	}
	free(v);
}

int					main(int argc, char **argv)
{
	t_instructions	*v1;
	t_instructions	*v2;

	if (argc >= 2)
	{
		if (!(v1 = (t_instructions *)ft_memalloc(sizeof(t_instructions))))
			throw("Error");
		v1->size = 0;
		v1->head = NULL;
		if (!(v2 = (t_instructions *)ft_memalloc(sizeof(t_instructions))))
			throw("Error");
		v2->size = 0;
		v2->head = NULL;
		get_instructions(argc, argv, v1, &set_stable_v1);
		get_instructions(argc, argv, v2, &set_stable_v2);
		print_instructions((v1->size < v2->size) ? v1 : v2);
		free_instructions(v1);
		free_instructions(v2);
	}
	else
		ft_putendl("Usage: ./push_swap <numbers>");
	return (0);
}
