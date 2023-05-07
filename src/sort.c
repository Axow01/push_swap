/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:36:44 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/07 01:45:26 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_given(t_data *data, int id)
{
	t_pile	*current;
	int		list_len;

	current = data->a;
	if (id == 0)
	{
		ft_pb(data);
		return ;
	}
	list_len = ft_list_lenght(current);
	if (list_len - id > id)
	{
		while (id-- > 0)
			ft_ra(data, 1);
	}
	else
	{
		while (id++ < list_len)
			ft_rra(data);
	}
	ft_pb(data);
}

int	ft_srch_small(t_data *data)
{
	t_pile	*current;
	int		small;
	int		i;

	current = data->a;
	small = current->nb;
	i = 0;
	while (current->next)
	{
		if (current->nb < small || (ft_list_lenght(data->a) == 2 &&
				small < current->next->nb))
		{
			small = current->nb;
			return (i);
		}
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_sort(t_data *data)
{
	int	i;

	i = ft_list_lenght(data->a);
	while (i-- > 1)
		ft_push_given(data, ft_srch_small(data));
	i = ft_list_lenght(data->b);
	while (i-- > 1)
		ft_pa(data);
}
