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
		if (current->nb == nb)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_transfer(void)
{
	int		first_nb;
	t_pile	*node;

	while (ft_list_lenght(get_data()->a) > 3)
	{
		first_nb = get_data()->a->nb;
		ft_pb(get_data());
		node = get_node(get_data()->b, first_nb);
		if (first_nb < ft_get_largest(get_data()->b))
		{
			node = get_node(get_data()->b, ft_get_largest(get_data()->b));
			if (node->next && node->next->nb < first_nb)
				ft_sb(get_data()->b);
			else
				ft_rb(get_data(), 1);
		}
	}
	ft_sort_small();
	while (ft_list_lenght(get_data()->b))
		ft_pa(get_data());
}

void	ft_sort(void)
{
	if (ft_list_lenght(get_data()->a) <= 3)
		ft_sort_small();
	ft_transfer();
	ft_rra(get_data());
	ft_rra(get_data());
	ft_rra(get_data());
	// ft_print_formated();
}
