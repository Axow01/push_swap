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
	while (ft_get_index(nb) != 2)
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

t_pile	*ft_smallest_cost_node(t_pile *pile)
{
	t_pile	*current;
	int		cost_small;

	current = pile;
	cost_small = current->step_needed;
	while (current)
	{
		if (current->step_needed < cost_small)
			cost_small = current->step_needed;
		current = current->next;
	}
	current = pile;
	while (current->step_needed != cost_small)
		current = current->next;
	return (current);
}

t_pile	*getlargest_node(t_pile *node, t_pile *future, bool reverse)
{
	if (reverse)
	{
		if (node->rrotate > future->rrotate)
		{
			future->rrotate = 0;
			return (node);
		}
		node->rrotate = 0;
		return (future);
	}
	if (node->rotate > future->rotate)
	{
		future->rotate = 0;
		return (node);
	}
	node->rotate = 0;
	return (future);
}

void	ft_double_rotate(t_pile *node_moving, t_pile *future_node)
{
	int	i;

	i = 0;
	if (node_moving->rotate && future_node->rotate)
	{
		i = ft_smallest_value(node_moving->rotate, future_node->rotate);
		while (i-- > 0)
			ft_rr(get_data());
		getlargest_node(node_moving, future_node, false)->rotate -= ft_smallest_value(node_moving->rotate, future_node->rotate);
	}
	else if (node_moving->rrotate && future_node->rrotate)
	{
		i = ft_smallest_value(node_moving->rrotate, future_node->rrotate);
		while (i-- > 0)
			ft_rrr(get_data());
		getlargest_node(node_moving, future_node, true)->rrotate -= ft_smallest_value(node_moving->rrotate, future_node->rrotate);
	}
	else if (ft_list_lenght(get_data()->b) < 3 && (node_moving->rotate || node_moving->rrotate))
	{
		if (node_moving->rotate)
		{
			i = future_node->rotate + future_node->rrotate;
			while (i-- > 0)
				ft_rr(get_data());
			node_moving->rotate -= future_node->rotate + future_node->rrotate;
		}
		else if (node_moving->rrotate)
		{
			i = future_node->rotate + future_node->rrotate;
			while (i-- > 0)
				ft_rrr(get_data());
			node_moving->rrotate -= future_node->rotate + future_node->rrotate;
		}
	}
}

void	ft_transfer(void)
{
	t_pile	*node_moving;
	t_pile	*future_node;
	int		i;

	node_moving = ft_smallest_cost_node(get_data()->a);
	future_node = get_node(get_data()->b, ft_get_future_pos(node_moving));
	i = 0;
	ft_double_rotate(node_moving, future_node);
	while (i++ < node_moving->rotate)
		ft_ra(get_data(), 1);
	i = 0;
	while (i++ < node_moving->rrotate)
		ft_rra(get_data());
	i = 0;
	while (i++ < future_node->rotate)
		ft_rb(get_data(), 1);
	i = 0;
	while (i++ < future_node->rrotate)
		ft_rrb(get_data());
	ft_pb(get_data());
	ft_indexing(get_data()->a);
	ft_indexing(get_data()->b);
	ft_all_cost(get_data()->a);
}

void	ft_sort(void)
{
	if (ft_list_lenght(get_data()->a) <= 3)
		ft_sort_small();
	ft_pb(get_data());
	ft_pb(get_data());
	ft_indexing(get_data()->a);
	ft_indexing(get_data()->b);
	ft_all_cost(get_data()->a);
	while (ft_list_lenght(get_data()->a) > 3)
		ft_transfer();
	ft_sort_small();
}
