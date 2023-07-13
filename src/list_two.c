/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:35:23 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/03 19:35:44 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pb(t_data *data)
{
	t_pile	*buffer;

	if (!data->a || !data)
		return ;
	buffer = data->a->next;
	data->a->next = data->b;
	data->b = data->a;
	data->a = buffer;
	ft_printf("pb\n");
}

void	ft_ra(t_data *data, int print)
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
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_data *data, int print)
{
	t_pile	**head;
	t_pile	*first;
	t_pile	*last;

	head = &data->b;
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
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_data *data)
{
	ft_ra(data, 0);
	ft_rb(data, 0);
}

//void	ft_rra(t_data *data)
// {
// 	// t_pile	*current;

// 	// current = data->a;
// 	// if (!current)
// 	// 	return ;
// 	// while (current->next && current != data->a)
// 	// 	current = current->next;
// 	// current->next = data->a;
// 	// current->previous->next = NULL;
// 	// current->previous = NULL;
// 	// data->a->previous = current;
// 	// data->a = current;
// 	// // write(1, "rra\n", 4);
// 	// Redo complet calice
// }

void	ft_rra(t_data *data)
{
	t_pile	*current;

	current = data->a;
	if (!current)
		return ;
	while (current->next)
		current = current->next;
	current->next = data->a;
	current->previous->next = NULL;
	current->next->previous = current;
	current->previous = NULL;
	data->a = current;
	ft_printf("rra\n");
}
