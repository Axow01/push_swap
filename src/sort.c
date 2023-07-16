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
	if (node->nb > ft_get_largest(get_data()->b) || node->nb < ft_get_smallest(get_data()->b))
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
	return (smallest_diff_index);
}

int	ft_get_rotations_side(t_pile *node, t_pile *stack)
{
	if (ft_list_lenght(stack) <= 3)
		return (2);
	if (node->index + 1 > ft_list_lenght(stack) / 2)
		return (1);
	return (0);
}

int	ft_cost(t_pile *node)
{
	int	total;
	int	b_side;

}

void	ft_all_cost(t_pile *pile)
{
	t_pile *current;

	current = pile;
	while (current)
	{
		current->step_needed = ft_cost(current);
		ft_printf("Cost: %d - NB: %d\n", current->step_needed, current->nb);
		current = current->next;
	}
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
	ft_print_formated();
}
