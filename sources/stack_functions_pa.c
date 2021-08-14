/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_pa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:19:12 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:19:21 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push(t_stack *stack, t_elem *elem)
{
	t_elem	*last;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			last = stack->head->prev;
			elem->prev = last;
			last->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

static t_elem		*pop(t_stack *stack)
{
	t_elem	*top;

	top = NULL;
	if (stack && stack->size)
	{
		top = stack->head;
		if (stack->size == 1)
			stack->head = NULL;
		else
		{
			stack->head = stack->head->next;
			top->prev->next = top->next;
			top->next->prev = top->prev;
		}
		top->prev = NULL;
		top->next = NULL;
		stack->size--;
	}
	return (top);
}

void				pa(t_data *d, char *instruction)
{
	push(d->a, pop(d->b));
	if (instruction)
		add_ins(d->c, instruction);
}

void				pb(t_data *d, char *instruction)
{
	push(d->b, pop(d->a));
	if (instruction)
		add_ins(d->c, instruction);
}
