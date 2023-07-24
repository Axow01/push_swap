/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:18:14 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/24 17:06:59 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*get_smallest_node(t_pile *pile, int nb)
{
	t_pile	*current;

	current = pile;
	while (current)
	{
		if (current->nb == nb)
			return (current);
		current = current->next;
	}
	return (NULL);
}

long int	ft_min_biggest(int nb, int nb2)
{
	if (nb > nb2)
		return ((long int)nb - (long int)nb2);
	return ((long int)nb2 - (long int)nb);
}

int	ft_find_position_a(t_pile *node)
{
	int	smallest_index;

	ft_indexing(get_data()->a);
	smallest_index = ft_get_smallgap(node);
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
