/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:18:14 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/16 20:57:51y mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*get_smallest_node(t_pile *pile, int nb)
{
	t_pile	*current;
current = pile; while (current)
	{
		if (current->nb == nb)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int	ft_min_biggest(int nb, int nb2)
{
	if (nb > nb2)
		return (nb - nb2);
	return (nb2 - nb);
}

int	ft_find_position_a(t_pile *node)
{
	t_pile	*current;
	int		smallest_gap;
	int		smallest_index;

	ft_indexing(get_data()->a);
	smallest_gap = ft_min_biggest(node->nb, ft_get_smallest(get_data()->a));
	smallest_index = get_smallest_node(get_data()->a, ft_get_smallest(get_data()->a))->index;
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
	node->rotate = 0;
	node->rrotate = 0;
	if (get_node(get_data()->a, smallest_index)->nb < node->nb)
		smallest_index++;
	if (smallest_index == ft_list_lenght(get_data()->a))
		smallest_index = 0;
	else if (smallest_index > ft_list_lenght(get_data()->a) / 2)
		node->rrotate = ft_list_lenght(get_data()->a) - smallest_index;
	else
		node->rotate = smallest_index;
	return (smallest_index);
}

void	ft_rotate_and_push_a(t_pile *node)
{
	while (node->rotate-- > 0)
		ft_ra(get_data(), 1);
	while (node->rrotate-- > 0)
		ft_rra(get_data());
	ft_pa(get_data());
}


void	finish(void)
{
	t_pile	*smallest;

	while (ft_list_lenght(get_data()->b) > 0)
	{
		// if (get_data()->b->nb == 5)
		// 	return ;
		ft_indexing(get_data()->a);
		ft_find_position_a(get_data()->b);
		ft_rotate_and_push_a(get_data()->b);
	}
	smallest = get_smallest_node(get_data()->a, ft_get_smallest(get_data()->a));
	if (smallest->index > ft_list_lenght(get_data()->a))
	{
		while (get_data()->a->nb != smallest->nb)
			ft_rra(get_data());
	}
	else
	{
		while (get_data()->a->nb != smallest->nb)
			ft_ra(get_data(), 1);
	}
}
