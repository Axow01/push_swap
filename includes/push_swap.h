/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:13 by mmarcott          #+#    #+#             */
/*   Updated: 2023/03/26 16:20:59 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int				nb;
	struct s_pile	*previous;
	struct s_pile	*next;
}					t_pile;

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	ft_swap(t_pile *a);

/* Return the number of elements in the list. */
int	ft_list_lenght(t_pile *pile);
#endif