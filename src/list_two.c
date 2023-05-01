/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:35:23 by mmarcott          #+#    #+#             */
/*   Updated: 2023/04/30 18:22:08 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pb(t_data *data)
{
	t_pile	*node;

	node = ft_calloc(1, sizeof(t_pile));
	node->next = data->b;
	data->b->previous = node;
	node->nb = data->a->nb;
	data->a = data->a->next;
	data->a->previous = ft_free(data->a->previous);
	data->b = node;
	ft_printf("pb\n");
}

void	ft_ra(t_data *data)
{
	t_pile	**head;
	t_pile	*first;
	t_pile	*last;

	head = &data->a;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	first = *head;
	*head = first->next;
	(*head)->previous = NULL;
	first->previous = last;
	first->next = NULL;
	last->next = first;
}
