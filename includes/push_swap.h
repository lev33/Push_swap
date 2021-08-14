/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:05:56 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/08/09 22:31:31 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

# define OK "OK"
# define KO "KO"

# define COLOR_OK "\e[32mOK\e[39m"
# define COLOR_KO "\e[31mKO\e[39m"

typedef enum
{
	false,
	true
}	t_bool;

typedef struct			s_elem
{
	int					number;
	ssize_t				index;
	t_bool				stable;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef struct			s_stack
{
	t_elem				*head;
	size_t				size;
	size_t				count;
	t_elem				*head_2;
}						t_stack;

typedef struct			s_rotation
{
	t_elem				*a_elem;
	t_elem				*b_elem;
	int					a_direction;
	int					b_direction;
	size_t				size;
	t_bool				is_set;
}						t_rotation;

typedef struct			s_inst
{
	char				*instruction;
	struct s_inst		*next;
}						t_inst;

typedef struct			s_instructions
{
	size_t				size;
	t_inst				*head;
}						t_instructions;

typedef struct			s_data
{
	t_stack				*a;
	t_stack				*b;
	t_instructions		*c;
}						t_data;

t_data					*get_data(int argc, char **argv);
size_t					set_stable_v1(t_elem *head_2);
size_t					set_stable_v2(t_elem *head_2);
void					select_stable_elems_in_a(t_data *d,
											size_t (*set_stable)(t_elem *));

void					sa(t_data *d, char *instruction);
void					sb(t_data *d, char *instruction);
void					ss(t_data *d, char *instruction);
void					ra(t_data *d, char *instruction);
void					rb(t_data *d, char *instruction);
void					rr(t_data *d, char *instruction);
void					rra(t_data *d, char *instruction);
void					rrb(t_data *d, char *instruction);
void					rrr(t_data *d, char *instruction);
void					pa(t_data *d, char *instruction);
void					pb(t_data *d, char *instruction);

void					move_from_a_to_b(t_data *d,
											size_t (*set_stable)(t_elem *));
void					move_from_b_to_a(t_data *d);

void					throw(char *str);

t_stack					*new_stack(void);
t_elem					*find_tmp_head(t_stack *a, int index);

void					add_ins(t_instructions *list, char *instruction);

void					execute_instruction(t_data *d, char *instruction);
void					free_stack(t_stack *stack);

size_t					ft_signedlen(intmax_t number);

#endif
