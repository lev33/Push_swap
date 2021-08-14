/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:21:23 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:21:33 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*new_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		throw("Error");
	stack->head = NULL;
	stack->size = 0;
	stack->count = 0;
	stack->head_2 = NULL;
	return (stack);
}

void			free_stack(t_stack *stack)
{
	size_t	i;
	t_elem	*current;
	t_elem	*delete;

	i = 0;
	current = stack->head;
	while (i++ < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
	}
	free(stack);
}

t_elem			*find_tmp_head(t_stack *a, int index)
{
	t_elem	*current;

	current = a->head;
	if (index < current->index)
	{
		while (index < current->prev->index
				&& current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (index > current->index
				&& current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

void			add_ins(t_instructions *v, char *instruction)
{
	t_inst *last;
	t_inst *inst;

	if (!(inst = (t_inst *)ft_memalloc(sizeof(t_inst))))
		throw("Error");
	if (!(inst->instruction = ft_strdup(instruction)))
		throw("Error");
	inst->next = NULL;
	if (v)
	{
		if (!v->head)
			v->head = inst;
		else
		{
			last = v->head;
			while (last->next)
				last = last->next;
			last->next = inst;
		}
		v->size++;
	}
}

void			execute_instruction(t_data *d, char *instruction)
{
	if (ft_strequ(instruction, "sa"))
		sa(d, NULL);
	else if (ft_strequ(instruction, "sb"))
		sb(d, NULL);
	else if (ft_strequ(instruction, "ss"))
		ss(d, NULL);
	else if (ft_strequ(instruction, "pa"))
		pa(d, NULL);
	else if (ft_strequ(instruction, "pb"))
		pb(d, NULL);
	else if (ft_strequ(instruction, "ra"))
		ra(d, NULL);
	else if (ft_strequ(instruction, "rb"))
		rb(d, NULL);
	else if (ft_strequ(instruction, "rr"))
		rr(d, NULL);
	else if (ft_strequ(instruction, "rra"))
		rra(d, NULL);
	else if (ft_strequ(instruction, "rrb"))
		rrb(d, NULL);
	else if (ft_strequ(instruction, "rrr"))
		rrr(d, NULL);
	else
		throw("Error");
}
