/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:31:34 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/03 17:55:35 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(char *message, int code)
{
	ft_printf("Error\n%s\n", message);
	exit(code);
}

void	ft_add_value_list(t_pile *stack, int value)
{
	t_pile	*current;

	current = stack;
	if (!current->nb)
	{
		current->nb = value;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = ft_calloc(1, sizeof(t_pile));
	if (!current->next)
		ft_exit("Calloc failled.\n", 1);
	current->next->previous = current;
	current = current->next;
	current->nb = value;
}

void	ft_free_stack(t_pile *stack)
{
	t_pile	*current;
	t_pile	*temp;

	current = stack;
	while (current->next && current->next != stack)
	{
		ft_printf("Current: %d - %p -> FREED\n", current->nb, current);
		temp = current;
		current = current->next;
		temp = ft_free(temp);
	}
	ft_printf("Current: %d - %p -> FREED\n", current->nb, current);
	current = ft_free(current);
}

void	ft_print_list(t_pile *a)
{
	t_pile	*current;

	current = a;
	while (current->next && current->next != a)
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
	ft_printf("%d\n", current->nb);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	if (argc == 1)
		ft_exit("./push_swap <number> <number> <number>> ...", 1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_exit("Calloc failled!\n", 1);
	data->a = NULL;
	data->b = ft_calloc(1, sizeof(t_pile));
	if (!data->b || !data->a)
		ft_exit("Calloc failled for data->a or data->b or data.\n", 1);
	i = 0;
	while (++i < argc)
		ft_add_value_list(data->a, ft_atoi(argv[i]));
	ft_print_list(data->a);
	ft_ra(data, 1);
	ft_rra(data);
	write(1, "\n\n", 2);
	ft_print_list(data->a);
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	data = ft_free(data);
	return (0);
}
