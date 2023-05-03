/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:35 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/03 17:37:26 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_pointer(char *message, void *p, void *p1)
{
	p = ft_free(p);
	p1 = ft_free(p1);
	ft_printf("%s", message);
	exit(1);
}
