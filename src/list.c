/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:32:16 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/03 16:48:45 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_list_lenght(t_pile *pile)
{
	t_pile	*current;
	int		i;

	current = pile;
	if (!current)
		return (0);
	i = 1;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_sa(t_pile *a)
{
	int	buffer;

	buffer = a->nb;
	a->nb = a->next->nb;
	a->next->nb = buffer;
	ft_printf("sa\n");
}

void	ft_sb(t_pile *b)
{
	int	buffer;

	buffer = b->nb;
	b->nb = b->next->nb;
	b->next->nb = buffer;
	ft_printf("sb\n");
}

void	ft_ss(t_pile *a, t_pile *b)
{
	int	buffer;

	buffer = b->nb;
	b->nb = b->next->nb;
	b->next->nb = buffer;
	buffer = a->nb;
	a->nb = a->next->nb;
	a->next->nb = buffer;
	ft_printf("ss\n");
}

void	ft_pa(t_data *data)
{
	t_pile	*buffer;

	if (!data->b || !data->a || !data)
		return ;
	buffer = data->b->next;
	data->b->next = data->a;
	data->b->next->previous = data->b;
	data->b->previous = NULL;
	data->a = data->b;
	data->b = buffer;
	if (data->b)
		data->b->previous = NULL;
	ft_printf("pa\n");
}
