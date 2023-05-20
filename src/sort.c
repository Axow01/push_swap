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

int	*ft_create_chunk(t_pile *pile, int chunk)
{
	int		i;
	t_pile	*current;
	int		*chunki;

	if (!pile)
		return (NULL);
	chunki = malloc(pile->chunk_size * sizeof(int));
	current = pile;
	i = -1;
	while (++i < chunk * pile->chunk_size && current)
		current = current->next;
	i = -1;
	while (++i < pile->chunk_size && current)
	{
		chunki[i] = current->nb;
		current = current->next;
	}
	get_data()->chunk->c = chunki;
	get_data()->chunk->i = get_data()->a->chunk_size;
	return (get_data()->chunk->c);
}

int	ft_get_small(int *chunk)
{
	int	i;
	int	b;
	int	small;
	int	*new;

	i = -1;
	small = chunk[0];
	while (++i < get_data()->chunk->i)
		if (chunk[i] < small)
			small = chunk[i];
	i = -1;
	b = 0;
	new = ft_calloc(get_data()->a->chunk_size - 1, sizeof(int));
	while (++i < get_data()->a->chunk_size)
		if (chunk[i] != small)
			new[b++] = chunk[i];
	get_data()->chunk->c = new;
	get_data()->chunk->i -= 1;
	return (small);
}

void	ft_push_small(t_pile *pile, int nb)
{
	t_pile	*current;
	int		i;
	bool	rotate;

	current = pile;
	i = 0;
	rotate = false;
	printf("Nb: %d\n", nb);
	while (current && current->nb != nb)
	{
		i++;
		printf("Current: %d\n", current->nb);
		current = current->next;
	}
	if (i < ft_list_lenght(pile) / 2)
		rotate = true;
	printf("I: %d\n", i);
	while (i-- > 0)
		ft_ra(get_data(), 1);
	ft_pb(get_data());
}

void	ft_sort(void)
{
	ft_define_chunk_size(get_data()->a);
	get_data()->chunk->c = ft_create_chunk(get_data()->a, 0);
	if (!get_data()->chunk->c)
		ft_exit_pointer("Failled to chunk bitch\n", NULL, get_data());
	ft_push_small(get_data()->a, ft_get_small(get_data()->chunk->c));
	ft_push_small(get_data()->a, ft_get_small(get_data()->chunk->c));
	ft_print_list(get_data()->a);
	write(1, "\n\n", 2);
	ft_print_list(get_data()->b);
}
