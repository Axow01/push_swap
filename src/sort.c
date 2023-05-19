/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:36:44 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/10 22:26:33 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk_size(t_pile *pile)
{
	int	i;
	int	size;

	i = 2;
	size = ft_list_lenght(pile);
	if (size == 0)
		return ;
	while (size % i == 0)
		i++;
	pile->chunk_size = size / (i - 1);
	pile->chunk_nb = i - 1;
}

t_pile	*ft_get_chunk(t_pile *pile, int chunk)
{
	t_pile	*current;
	t_pile	*chunkp;
	int		i;

	if (!pile)
		return (NULL);
	i = -1;
	current = pile;
	while (++i < chunk * pile->chunk_size)
		current = current->next;
	i = -1;
	chunkp = ft_calloc(1, sizeof(t_pile));
	if (!chunkp)
		ft_exit_pointer("Failled to calloc <chunkp> ln:43\n", NULL, get_data());
	while (++i < pile->chunk_size)
	{
		ft_add_value_list(chunkp, current->nb);
		current = current->next;
	}
	get_data()->chunk = chunkp;
	return (get_data()->chunk);
}

int	ft_find_smallest(t_pile *chunk)
{
	t_pile	*current;
	int		smallest;
	int		index;

	if (!chunk)
		ft_exit_pointer("Chunk inexistant !\n", NULL, get_data());
	ft_print_list(chunk);
	current = chunk;
	smallest = 0;
	index = 0;
	while (current)
	{
		if (smallest > current->nb)
			smallest = current->nb;
		current = current->next;
		index++;
	}
	current = chunk;
	while (current && current->nb != smallest && --index >= 0)
		current = current->previous;
	return (index - 1);
}

void	ft_sort(void)
{
	ft_define_chunk_size(get_data()->a);
	printf("Smallest index: %d\n", ft_find_smallest(ft_get_chunk(get_data()->a, 0)));
	ft_exit_pointer("jsp\n", NULL, get_data());
}
