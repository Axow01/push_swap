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

void	ft_sort(void)
{
	ft_print_list(get_data()->a);
	ft_print_list(ft_create_chunk(2, 0, get_data()->a));
}
