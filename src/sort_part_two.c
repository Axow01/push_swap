/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:59:28 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/16 10:59:48 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
