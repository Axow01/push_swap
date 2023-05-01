/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:05:15 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/01 15:17:53 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrb(t_data *data)
{
	t_pile	*current;

	current = data->b;
	while (current->next)
		current = current->next;
	current->next = data->b;
	current->previous = NULL;
	data->b->previous = current;
	data->b = current;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_data *data)
{
	t_pile	*current;

	current = data->b;
	while (current->next)
		current = current->next;
	current->next = data->b;
	current->previous = NULL;
	data->b->previous = current;
	data->b = current;
	current = data->a;
	while (current->next)
		current = current->next;
	current->next = data->a;
	current->previous = NULL;
	data->a->previous = current;
	data->b = current;
	write(1, "rrr\n", 4);
}
