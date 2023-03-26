/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:32:16 by mmarcott          #+#    #+#             */
/*   Updated: 2023/03/26 17:48:25 by mmarcott         ###   ########.fr       */
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

void	ft_swap(t_pile *a)
{
	int	buffer;

	if (ft_list_lenght(a) <= 1)
		return ;
	buffer = a->nb;
	a->nb = a->next->nb;
	a->next->nb = buffer;
}

void    ft_ss(t_pile *a, t_pile *b)
{
    ft_swap(a);
    ft_swap(b);
}
