/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_ra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:18:18 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:18:28 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *d, char *instruction)
{
	if (d->a && d->a->head)
		d->a->head = d->a->head->next;
	if (instruction)
		add_ins(d->c, instruction);
}

void	rb(t_data *d, char *instruction)
{
	if (d->b && d->b->head)
		d->b->head = d->b->head->next;
	if (instruction)
		add_ins(d->c, instruction);
}

void	rr(t_data *d, char *instruction)
{
	ra(d, NULL);
	rb(d, NULL);
	if (instruction)
		add_ins(d->c, instruction);
}
