/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:27:55 by mmarcott          #+#    #+#             */
/*   Updated: 2023/04/07 23:44:34 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*get_data(void)
{
	static t_data	*data;

	if (!data)
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
			ft_exit("Failed to malloc the data structure.\n", 1);
		data->chunk = ft_calloc(1, sizeof(t_chunk));
		if (!data->chunk)
			ft_exit_pointer("lul\n", NULL, data);
	}
	return (data);
}

void	ft_remove_element(t_pile *pile, int index)
{
	t_pile	*current;
	t_pile	*buffer;

	if (!pile)
		return ;
	current = pile;
	while (index-- > 0 && current)
	{
		current = current->next;
	}
	buffer = current->previous;
	buffer->next = current->next;
	current->next->previous = buffer;
	current = ft_free(current);
	current = buffer;
}

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}
