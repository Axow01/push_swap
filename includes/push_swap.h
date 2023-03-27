/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:13 by mmarcott          #+#    #+#             */
/*   Updated: 2023/03/27 14:29:15 by mmarcott         ###   ########.fr       */
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

typedef struct s_data
{
	t_pile			*a;
	t_pile			*b;
}					t_data;

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. Modifier 0 for sb and 1 for sa. */
void				ft_sa(t_pile *a);

/* Swap the first 2 elements at the top of stack b. */
void				ft_sb(t_pile *b);

/* Return the number of elements in the list. */
int					ft_list_lenght(t_pile *pile);

/* Do the function ft_swap() for a and b. */
void				ft_ss(t_pile *a, t_pile *b);

/* Put the first elements of b at the top of a. */
void				ft_pa(t_data *data);

void				*ft_free(void *ptr);

#endif