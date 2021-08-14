/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:20:05 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/06/12 09:20:15 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				throw(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

static size_t		ft_unsignedlen(uintmax_t number)
{
	size_t			size;

	size = 1;
	while ((number /= 10))
		size++;
	return (size);
}

size_t				ft_signedlen(intmax_t num)
{
	size_t			size;

	size = ft_unsignedlen((uintmax_t)((num < 0) ? -num : num));
	return (size + ((num < 0 && size) ? 1 : 0));
}
