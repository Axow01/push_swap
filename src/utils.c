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
	}
	return (data);
}

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}
