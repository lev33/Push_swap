/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:19:34 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:20:50 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include "vs.h"

static void			print_stack(t_stack *stack, t_elem **current, size_t i)
{
	size_t	spaces;
	int		int_max;

	int_max = (int)((unsigned)(~0L) >> 1);
	if (i < stack->size)
	{
		ft_putchar(' ');
		spaces = ft_signedlen(int_max) + 1 -
			ft_signedlen((*current)->number);
		while (spaces > 0)
		{
			ft_putchar(' ');
			spaces--;
		}
		ft_putnbr((*current)->number);
		ft_putchar(' ');
		(*current) = (*current)->next;
	}
	else
		ft_putstr("             ");
}

static void			print_stacks(t_stack *a, t_stack *b)
{
	size_t			i;
	t_elem			*a_current;
	t_elem			*b_current;

	i = 0;
	a_current = a->head;
	b_current = b->head;
	ft_putendl("+-------------+-------------+");
	while (i < a->size || i < b->size)
	{
		ft_putchar('|');
		print_stack(a, &a_current, i);
		ft_putchar('|');
		print_stack(b, &b_current, i);
		ft_putchar('|');
		ft_putstr("\n");
		i++;
	}
	ft_putendl("+------a------+------b------+");
}

static t_bool		is_sorted(t_stack *stack)
{
	size_t			i;
	t_elem			*cur;
	int				number;

	i = 1;
	cur = stack->head->next;
	number = stack->head->number;
	while (i++ < stack->size)
	{
		if (cur->number < number)
			return (false);
		number = cur->number;
		cur = cur->next;
	}
	return (true);
}

static void			checker(int argc, char **argv, t_bool v, t_bool c)
{
	t_data	*d;
	char	*line;
	ssize_t	size;

	d = get_data(argc, argv);
	ft_putstr((v) ? "Init a and b:\n" : NULL);
	(v) ? print_stacks(d->a, d->b) : 0;
	while ((size = get_next_line(0, &line)) > 0)
	{
		execute_instruction(d, line);
		ft_putstr((v) ? "Exec " : NULL);
		ft_putstr((v) ? line : NULL);
		ft_putstr((v) ? ":\n" : NULL);
		(v) ? print_stacks(d->a, d->b) : 0;
		free(line);
	}
	(size == -1) ? throw("Error") : 0;
	if (d->b->head == NULL && is_sorted(d->a))
		ft_putendl((c) ? COLOR_OK : OK);
	else
		ft_putendl((c) ? COLOR_KO : KO);
	free_stack(d->a);
	free_stack(d->b);
	free(d);
}

int					main(int argc, char **argv)
{
	t_bool	v;
	t_bool	c;
	t_bool	h;

	v = false;
	c = false;
	h = false;
	while (argc >= 2 && (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c")
				|| !ft_strcmp(argv[1], "-h")))
	{
		if (!ft_strcmp(argv[1], "-v"))
			v = true;
		else if (!ft_strcmp(argv[1], "-c"))
			c = true;
		else if (!ft_strcmp(argv[1], "-h"))
			h = true;
		argv++;
		argc--;
	}
	if (argc >= 2 && !h)
		checker(argc, argv, v, c);
	else if (h)
		ft_putendl("-v\tDisplay the stack’s status after each operation\n"
				"-c\tShow in colours the last operation\n-h\tHelp");
	return (0);
}
