/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:35 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/03 18:47:46 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_pointer(char *message, void *p, t_data *data)
{
	write(1, "got to ft_free_pointer\n", 24);
	p = ft_free(p);
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	data = ft_free(data);
	ft_printf("%s", message);
	exit(1);
}
