/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:59:28 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/19 13:29:31 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	smaller_stack(t_pile *node_moving, t_pile *future_node)
{
	int	i;

	i = 0;
	if (ft_list_lenght(get_data()->b) < 3
		&& (node_moving->rotate || node_moving->rrotate))
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

void	ft_double_rotate(t_pile *node_moving, t_pile *future_node)
{
	int	i;

	i = 0;
	if (node_moving->rotate && future_node->rotate)
	{
		i = ft_smallest_value(node_moving->rotate, future_node->rotate);
		while (i-- > 0)
			ft_rr(get_data());
		i = ft_smallest_value(node_moving->rotate, future_node->rotate);
		getlargest_node(node_moving, future_node, false)->rotate -= i;
	}
	else if (node_moving->rrotate && future_node->rrotate)
	{
		i = ft_smallest_value(node_moving->rrotate, future_node->rrotate);
		while (i-- > 0)
			ft_rrr(get_data());
		i = ft_smallest_value(node_moving->rrotate, future_node->rrotate);
		getlargest_node(node_moving, future_node, true)->rrotate -= i;
	}
	else if (ft_list_lenght(get_data()->b) < 3
		&& (node_moving->rotate || node_moving->rrotate))
		smaller_stack(node_moving, future_node);
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
