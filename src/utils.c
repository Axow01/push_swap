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
#include <stdio.h>

t_data	*get_data(void)
{
	static t_data	*data;

	if (!data)
	{
		data = mms_alloc(1, sizeof(t_data));
		data->a = NULL;
		data->b = NULL;
	}
	return (data);
}

void	ft_print_formated(void)
{
	write(1, "\nA:\n", 4);
	ft_print_list(get_data()->a);
	write(1, "\nB:\n", 4);
	ft_print_list(get_data()->b);
	write(1, "\n", 1);
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

void	ft_add_value(t_pile *pile, int value)
{
	t_pile	*current;

	if (!pile)
	{
		pile = mms_alloc(1, sizeof(t_pile));
		pile->nb = value;
		pile->next = NULL;
		get_data()->b = pile;
		return ;
	}
	current = pile;
	while (current->next)
		current = current->next;
	current->next = mms_alloc(1, sizeof(t_pile));
	current = current->next;
	current->nb = value;
	current->next = NULL;
}

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}
