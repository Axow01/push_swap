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
#include <stdio.h>

t_pile	*ft_remove_first(t_pile *pile)
{
	t_pile	*current;

	current = pile;
	current = current->next;
	mms_free(pile);
	pile = current;
	return (pile);
}

t_pile	*ft_create_chunk(int size, int statingPoint, t_pile *list)
{
	t_pile	*current;
	t_pile	*new;
	int		i;

	i = 0;
	new = mms_alloc(1, sizeof(t_pile));
	if (!list || size <= 0 || statingPoint < 0)
		return (NULL);
	current = list;
	while (current && i++ != statingPoint)
		current = current->next;
	i = 0;
	while (current && i++ < size)
	{
		ft_add_value(new, current->nb);
		current = current->next;
	}
	new = ft_remove_first(new);
	return (new);
}

void	ft_jsp(t_pile *pile)
{
	if (!pile)
		return ;
	if (!pile->next)
		ft_pb(get_data());
	else if (pile->nb > pile->next->nb)
		ft_pb(get_data());
	else
	{
		ft_ra(get_data(), 1);
		ft_pb(get_data());
		ft_rra(get_data());
	}
	ft_pb(get_data());
}

void	ft_sort(void)
{
	ft_print_list(get_data()->a);
	while (ft_list_lenght(get_data()->a))
		ft_jsp(get_data()->a);
	write(1, "\nA:\n", 4);
	ft_print_list(get_data()->a);
	write(1, "\nB:\n", 4);
	ft_print_list(get_data()->b);
	get_data()->b->chunk_size = (ft_list_lenght(get_data()->b) - 1) / 2;
	printf("%d\n", get_data()->b->chunk_size);
}
