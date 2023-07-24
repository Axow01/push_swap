/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:37:03 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/24 14:50:42 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atoli(const char *str)
{
	long int	total;
	int			i;
	int			sign;

	total = 0;
	i = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit((int)str[i]))
			total = total * 10 + str[i] - '0';
		i++;
	}
	return (total * sign);
}
