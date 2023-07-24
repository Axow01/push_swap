/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:36:44 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/10 22:26:33 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_index(int nb)
{
	t_pile	*current;
	int		i;

	current = get_data()->a;
	i = 0;
	while (current)
	{
		if (current->nb == nb)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

void	ft_sort_small(void)
{
	t_pile	*current;
	int		nb;

	current = get_data()->a;
	nb = current->nb;
	while (current)
	{
		if (current->nb > nb)
			nb = current->nb;
		current = current->next;
	}
	if (ft_list_lenght(get_data()->a) == 2 && !ft_check_sort())
		ft_sa(get_data()->a);
	while (ft_get_index(nb) != 2 && !ft_check_sort())
		ft_ra(get_data(), 1);
	if (!ft_check_sort())
		ft_sa(get_data()->a);
}

t_pile	*get_node(t_pile *pile, int nb)
{
	t_pile	*current;

	current = pile;
	while (current)
	{
		if (current->index == nb)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	push_smallest(void)
{
	t_pile	*smallest;

	ft_indexing(get_data()->a);
	smallest = get_smallest_node(get_data()->a, ft_get_smallest(get_data()->a));
	smallest->rotate = 0;
	smallest->rrotate = 0;
	if (smallest->index > ft_list_lenght(get_data()->a) / 2)
		smallest->rrotate = ft_list_lenght(get_data()->a) - smallest->index;
	else
		smallest->rotate = smallest->index;
	while (smallest->rotate--)
		ft_ra(get_data(), 1);
	while (smallest->rrotate--)
		ft_rra(get_data());
	ft_pb(get_data());
}

void	ft_sort(void)
{
	if (ft_check_sort())
		return ;
	if (ft_list_lenght(get_data()->a) <= 3)
	{
		ft_sort_small();
		return ;
	}
	push_smallest();
	push_smallest();
	ft_indexing(get_data()->a);
	ft_indexing(get_data()->b);
	ft_all_cost(get_data()->a);
	while (ft_list_lenght(get_data()->a) > 3)
		ft_transfer();
	ft_sort_small();
	finish();
}
