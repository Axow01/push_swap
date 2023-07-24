/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:05:15 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/03 19:37:59 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrb(t_data *data)
{
	t_pile	*current;

	current = data->b;
	while (current->next)
		current = current->next;
	current->next = data->b;
	current->previous->next = NULL;
	current->previous = NULL;
	data->b->previous = current;
	data->b = current;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_data *data)
{
	t_pile	*current;

	current = data->b;
	while (current->next)
		current = current->next;
	current->next = data->b;
	if (current->previous)
		current->previous->next = NULL;
	current->previous = NULL;
	data->b->previous = current;
	data->b = current;
	current = data->a;
	if (!current)
		return ;
	while (current->next)
		current = current->next;
	current->next = data->a;
	if (current->previous)
		current->previous->next = NULL;
	current->next->previous = current;
	current->previous = NULL;
	data->a = current;
	write(1, "rrr\n", 4);
}

int	ft_get_smallgap(t_pile *node)
{
	t_pile			*current;
	long int		smallest_gap;
	int				smallest_index;

	smallest_gap = ft_min_biggest(node->nb, ft_get_smallest(get_data()->a));
	smallest_index = get_smallest_node(get_data()->a,
			ft_get_smallest(get_data()->a))->index;
	current = get_data()->a;
	while (current)
	{
		if (smallest_gap >= ft_min_biggest(node->nb, current->nb))
		{
			smallest_gap = ft_min_biggest(node->nb, current->nb);
			smallest_index = current->index;
		}
		current = current->next;
	}
	return (smallest_index);
}

void	ft_indexing(t_pile *pile)
{
	t_pile	*current;
	int		i;

	current = pile;
	i = 0;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}
