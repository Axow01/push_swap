/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:35 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/06 15:12:48 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_pointer(char *message, void *p, t_data *data)
{
	(void)p;
	(void)data;
	mms_kill(message, true, EXIT_FAILURE);
}

void	ft_check_twins(t_data *data)
{
	t_pile	*current;
	t_pile	*compare;

	current = data->a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (compare->nb == current->nb)
				ft_exit_pointer("Error\n", NULL,
					data);
			compare = compare->next;
		}
		current = current->next;
	}
}

int	ft_get_largest(t_pile *pile)
{
	t_pile	*current;
	int		largestnb;

	current = pile;
	largestnb = current->nb;
	while (current)
	{
		if (current->nb > largestnb)
			largestnb = current->nb;
		current = current->next;
	}
	return (largestnb);
}

int	ft_get_smallest(t_pile *pile)
{
	int		smallestnb;
	t_pile	*current;

	current = pile;
	smallestnb = current->nb;
	while (current)
	{
		if (current->nb < smallestnb)
			smallestnb = current->nb;
		current = current->next;
	}
	return (smallestnb);
}

int	ft_smallest_value(int nb, int nb2)
{
	if (nb > nb2)
		return (nb2);
	return (nb);
}
