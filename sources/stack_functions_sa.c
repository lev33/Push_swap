/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_sa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:18:52 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:19:00 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_elem *first,
		t_elem *second,
		t_stack *stack)
{
	t_elem	*prev;
	t_elem	*next;

	prev = first->prev;
	next = second->next;
	prev->next = second;
	second->prev = prev;
	first->next = next;
	next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void		sa(t_data *d, char *instruction)
{
	if (d->a && d->a->head && d->a->size >= 2)
		swap(d->a->head, d->a->head->next, d->a);
	if (instruction)
		add_ins(d->c, instruction);
}

void		sb(t_data *d, char *instruction)
{
	if (d->b && d->b->head && d->b->size >= 2)
		swap(d->b->head, d->b->head->next, d->b);
	if (instruction)
		add_ins(d->c, instruction);
}

void		ss(t_data *d, char *instruction)
{
	sa(d, NULL);
	sb(d, NULL);
	if (instruction)
		add_ins(d->c, instruction);
}
