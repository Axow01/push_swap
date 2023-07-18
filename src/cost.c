/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:55:35 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/18 13:48:05 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_future_pos(t_pile *node)
{
	t_pile	*stack_b;
	int		smallest_diff;
	int		smallest_diff_index;

	stack_b = get_data()->b;
	while (stack_b->nb != ft_get_largest(get_data()->b))
		stack_b = stack_b->next;
	smallest_diff = ft_get_largest(get_data()->b) - node->nb;
	smallest_diff_index = stack_b->index;
	if (node->nb > ft_get_largest(get_data()->b)
		|| node->nb < ft_get_smallest(get_data()->b))
		return (stack_b->index);
	stack_b = get_data()->b;
	while (stack_b)
	{
		if (stack_b->nb > node->nb && (stack_b->nb - node->nb) < smallest_diff)
		{
			smallest_diff = stack_b->nb - node->nb;
			smallest_diff_index = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	if (smallest_diff_index + 1 != ft_list_lenght(get_data()->b))
		return (smallest_diff_index + 1);
	return (0);
}

int	ft_get_rotations_side(t_pile *node, t_pile *stack)
{
	if (ft_list_lenght(stack) < 3)
		return (2);
	if (node->index + 1 > ft_list_lenght(stack) / 2)
		return (1);
	return (0);
}

int	ft_cost_optimise(t_pile *node, t_pile *future_node)
{
	int	total_eco;

	total_eco = 0;
	if (node->rotate && future_node->rotate)
		total_eco += ft_smallest_value(node->rotate, future_node->rotate);
	else if (node->rrotate && future_node->rrotate)
		total_eco += ft_smallest_value(node->rrotate, future_node->rrotate);
	else if (ft_list_lenght(get_data()->b) < 3
		&& (node->rotate || node->rrotate))
		total_eco += future_node->rotate + future_node->rrotate;
	return (total_eco);
}

int	ft_cost(t_pile *node)
{
	t_pile	*future_node;
	int		list_lenght;

	future_node = get_node(get_data()->b, ft_get_future_pos(node));
	future_node->rotate = 0;
	future_node->rrotate = 0;
	node->rrotate = 0;
	node->rotate = 0;
	list_lenght = ft_list_lenght(get_data()->b);
	if (future_node->index + 1 > ft_get_largest(get_data()->b) / 2)
		future_node->rrotate = list_lenght - future_node->index;
	else
		future_node->rotate = future_node->index;
	if (node->index + 1 > ft_list_lenght(get_data()->a) / 2)
		node->rrotate = ft_list_lenght(get_data()->a) - node->index;
	else
		node->rotate = node->index;
	return (future_node->rrotate + future_node->rotate + node->rotate
		+ node->rrotate + 1 - ft_cost_optimise(node, future_node));
}

void	ft_all_cost(t_pile *pile)
{
	t_pile	*current;

	current = pile;
	while (current)
	{
		current->step_needed = ft_cost(current);
		current = current->next;
	}
}
