/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:21:00 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:22:47 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_stack(t_stack *a)
{
	size_t			i;
	size_t			j;
	t_elem			*m;
	t_elem			*n;

	if (!a->size)
		throw("Error");
	i = 0;
	m = a->head;
	while (i++ < a->size)
	{
		j = i;
		n = m->next;
		while (j++ < a->size)
		{
			if (m->number == n->number)
				throw("Error");
			n = n->next;
		}
		m = m->next;
	}
}

static void		add_number(t_stack *a, int number)
{
	t_elem	*last;
	t_elem	*new;

	if (!(new = (t_elem *)ft_memalloc(sizeof(t_elem))))
		throw("Error");
	new->number = number;
	new->index = -1;
	new->stable = false;
	if (!a->head)
	{
		a->head = new;
		a->head->prev = a->head;
		a->head->next = a->head;
	}
	else
	{
		last = a->head->prev;
		new->prev = last;
		last->next = new;
		new->next = a->head;
		a->head->prev = new;
	}
	a->size++;
}

static void		set_index(t_stack *a)
{
	size_t			index;
	size_t			i;
	int				is_max;
	t_elem			*cur;
	t_elem			*max;

	index = a->size;
	while (index--)
	{
		i = 0;
		max = NULL;
		is_max = 0;
		cur = a->head;
		while (i++ < a->size)
		{
			if ((cur->index == -1) && (!is_max || cur->number > max->number))
			{
				is_max = 1;
				max = cur;
			}
			cur = cur->next;
		}
		max->index = index;
	}
}

static void		read_argv(t_stack *a, int argc, char **argv)
{
	int		i;
	char	**numbers;

	if (argc == 2)
	{
		i = 0;
		numbers = ft_strsplit(argv[1], ' ');
		while (numbers[i])
		{
			if (!ft_isint(numbers[i]))
				throw("Error");
			add_number(a, ft_atoi(numbers[i++]));
		}
		ft_free_arr(numbers);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_isint(argv[i]))
				throw("Error");
			add_number(a, ft_atoi(argv[i++]));
		}
	}
}

t_data			*get_data(int argc, char **argv)
{
	t_data		*d;

	if (!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		throw("Error");
	d->a = new_stack();
	d->b = new_stack();
	read_argv(d->a, argc, argv);
	check_stack(d->a);
	set_index(d->a);
	return (d);
}
