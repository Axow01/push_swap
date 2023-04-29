/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:35:23 by mmarcott          #+#    #+#             */
/*   Updated: 2023/04/29 18:06:04 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pb(t_data *data)
{
	t_pile	*node;

	node = ft_calloc(1, sizeof(t_pile));
	node->next = data->b;
	data->b->previous = node;
	node->nb = data->a->nb;
	data->a = data->a->next;
	data->a->previous = ft_free(data->a->previous);
	data->b = node;
	ft_printf("pb\n");
}

void	ft_ra(t_data *data)
{
	t_pile	*last;
	t_pile	*second_last;

	if (data->a && data->a->next)
	{
		last = data->a;
		while (last->next != data->a)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = data->a;
		data->a = last;
	}
	write(1, "ra\n", 3);
}

void	ft_rb(t_data *data)
{
	t_pile	*last;

	if (data->b && data->b->next)
	{
		last = data->b;
		while (last->next)
			last = last->next;
		last->next = data->b;
		data->b = data->b->next;
		last->next->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	ft_rr(t_data *data)
{
	t_pile	*last;

	if (data->a && data->a->next)
	{
		last = data->a;
		while (last->next)
			last = last->next;
		last->next = data->a;
		data->a = data->a->next;
		last->next->next = NULL;
	}
	if (data->b && data->b->next)
	{
		last = data->b;
		while (last->next)
			last = last->next;
		last->next = data->b;
		data->b = data->b->next;
		last->next->next = NULL;
	}
	write(1, "rr\n", 3);
}

void	ft_rra(t_data *data)
{
	t_pile	*last;
	t_pile	*second_last;

	if (data->a && data->a->next)
	{
		last = data->a;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = data->a;
		data->a = last;
	}
	write(1, "rra\n", 4);
}
