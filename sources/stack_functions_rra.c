/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_rra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:18:38 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:18:44 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *d, char *instruction)
{
	if (d->a && d->a->head)
		d->a->head = d->a->head->prev;
	if (instruction)
		add_ins(d->c, instruction);
}

void	rrb(t_data *d, char *instruction)
{
	if (d->b && d->b->head)
		d->b->head = d->b->head->prev;
	if (instruction)
		add_ins(d->c, instruction);
}

void	rrr(t_data *d, char *instruction)
{
	rra(d, NULL);
	rrb(d, NULL);
	if (instruction)
		add_ins(d->c, instruction);
}
