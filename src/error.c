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
	p = ft_free(p);
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	ft_printf("%s", message);
	exit(1);
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
				ft_exit_pointer("There is two identical numbers ?!\n", NULL,
					data);
			compare = compare->next;
		}
		current = current->next;
	}
}
