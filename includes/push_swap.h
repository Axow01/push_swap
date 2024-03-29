/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:13 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/07 01:33:54 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libmms/libmms.h" // This is the memory management system.

typedef struct s_pile
{
	int				nb;
	struct s_pile	*previous;
	struct s_pile	*next;
	int				step_needed;
	int				rotate;
	int				rrotate;
	int				index;
}					t_pile;

typedef struct s_chunk
{
	int	*c;
	int	i;
}				t_chunk;

typedef struct s_data
{
	t_pile			*a;
	t_pile			*b;
	int				args;
}					t_data;

/* Exit the program. Without any free to use only
if you don't have values to free. */
void				ft_exit(char *message, int code);

/* This function exit the program but has the ability
to free two pointers before quitting. */
void				ft_exit_pointer(char *message, void *p, t_data *data);

/* This function frees all the elements of the stack. */
// void				ft_free_stack(t_pile *stack);

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
Modifier 0 for sb and 1 for sa. */
void				ft_sa(t_pile *a);

/* Swap the first 2 elements at the top of stack b. */
void				ft_sb(t_pile *b);

/* Return the number of elements in the list. */
int					ft_list_lenght(t_pile *pile);

/* Do the function ft_swap() for a and b. */
void				ft_ss(t_pile *a, t_pile *b);

/* Put the first elements of b at the top of a. */
void				ft_pa(t_data *data);

/* Free any calloced pointer. And return NULL always. */
void				*ft_free(void *ptr);

/* Put the first elements of a at the top of b. */
void				ft_pb(t_data *data);

/* Shift up all the elements of stack a by 1.
The firts element becomes the last one. */
void				ft_ra(t_data *data, int print);

/* Shift up all the elements of stack b by 1.
The first element becomes the last one. */
void				ft_rb(t_data *data, int print);

/* ft_ra and ft_rb at the same time. */
void				ft_rr(t_data *data);

/* Shift down all the element of stack a by 1. */
void				ft_rra(t_data *data);

/* Shift down all the elements of stack b by 1.
The last element become the first. */
void				ft_rrb(t_data *data);

/* ft_rra and ft_rrb at the same time. */
void				ft_rrr(t_data *data);

/* Eventually put the function usage here. */
int					ft_parsing(char **args, int argc, t_data *data);

/* This function add value to an stack. */
int					ft_add_value_list(t_pile *stack, int value, int who);

/* Verifies that there is no duplicate numbers in the stack.
If there is then free and exit. */
void				ft_check_twins(t_data *data);

/* This sort the stacks. */
void				ft_sort(void);

/* Prints a stack you .... */
void				ft_print_list(t_pile *a);

/* This give the variable data. */
t_data				*get_data(void);

/* This function add a value to the list given, it's not like the
 other one because this one has nothing to do with stack a or b. */
void				ft_add_value(t_pile *pile, int value);

void				ft_print_formated(void);

bool				ft_check_sort(void);

int					ft_get_largest(t_pile *pile);

int					ft_get_smallest(t_pile *pile);

int					ft_smallest_value(int nb, int nb2);

void				ft_indexing(t_pile *pile);

void				ft_all_cost(t_pile *pile);

t_pile				*get_node(t_pile *pile, int nb);

int					ft_get_future_pos(t_pile *node);

void				ft_transfer(void);

void				finish(void);

int					ft_get_smallgap(t_pile *node);

t_pile				*get_smallest_node(t_pile *pile, int nb);

long int			ft_min_biggest(int nb, int nb2);

long int			ft_atoli(const char *str);

#endif
