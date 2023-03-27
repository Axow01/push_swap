/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:32:16 by mmarcott          #+#    #+#             */
/*   Updated: 2023/03/27 14:39:20 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_list_lenght(t_pile *pile)
{
	t_pile	*current;
	int		i;

	current = pile;
	if (!current)
		return (0);
	i = 1;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_sa(t_pile *a)
{
	int	buffer;

	buffer = a->nb;
	a->nb = a->next->nb;
	a->next->nb = buffer;
	ft_printf("sa\n");
}

void	ft_sb(t_pile *b)
{
	int	buffer;

	buffer = b->nb;
	b->nb = b->next->nb;
	b->next->nb = buffer;
	ft_printf("sb\n");
}

void	ft_ss(t_pile *a, t_pile *b)
{
	int	buffer;

	buffer = b->nb;
	b->nb = b->next->nb;
	b->next->nb = buffer;
	buffer = a->nb;
	a->nb = a->next->nb;
	a->next->nb = buffer;
	ft_printf("ss\n");
}

void	ft_pa(t_data *data)
{
	t_pile *node;

	node = ft_calloc(1, sizeof(t_pile));
	node->next = data->a;
	data->a->previous = node;
	node->nb = data->b->nb;
	data->b = data->b->next;
	data->b->previous = ft_free(data->b->previous);
	data->a = node;
	ft_printf("pa\n");
}
