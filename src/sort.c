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

t_pile	*ft_create_chunk(size_t size, int statingPoint, t_pile *list)
{
	t_pile	*current;
	t_pile	*new;
	int	i;

	i = 0;
	new = NULL;
	if (!list || size <= 0 || statingPoint < 0)
		return (NULL);
	current = list;
	while (current && i++ != statingPoint)
		current = current->next;
	i = 0;
	while (current && i++ < (int)size)
	{
		ft_add_value(new, current->nb);
		current = current->next;
	}
	return (new);
}

void	ft_sort(void)
{
	t_pile	*chunk;

	chunk = ft_create_chunk(2, 0, get_data()->a);
	ft_print_list(chunk);
}
