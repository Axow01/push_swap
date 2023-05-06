/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:31:34 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/06 19:14:29 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(char *message, int code)
{
	ft_printf("Error\n%s\n", message);
	exit(code);
}

int	ft_add_value_list(t_pile *stack, int value)
{
	t_pile	*current;

	current = stack;
	if (!current->nb)
	{
		current->nb = value;
		return (1);
	}
	while (current->next)
		current = current->next;
	current->next = ft_calloc(1, sizeof(t_pile));
	if (!current->next)
		return (0);
	current->next->previous = current;
	current = current->next;
	current->nb = value;
	return (1);
}

void	ft_free_stack(t_pile *stack)
{
	t_pile	*current;
	t_pile	*temp;

	if (!stack)
		return ;
	current = stack;
	while (current->next && current)
	{
		ft_printf("Current: %d - %p -> ", current->nb, current);
		temp = current;
		current = current->next;
		temp = ft_free(temp);
		write(1, "FREED\n", 7);
	}
	ft_printf("Current: %d - %p -> ", current->nb, current);
	current = ft_free(current);
	write(1, "FREED\n", 7);
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
	t_data	data;

	if (argc == 1)
		ft_exit("./push_swap <number> <number> <number>> ...", 1);
	data.a = ft_calloc(1, sizeof(t_pile));
	data.b = ft_calloc(1, sizeof(t_pile));
	if (!data.b || !data.a || ft_parsing(argv, argc, &data) == 0)
		ft_exit_pointer("Calloc error or parsing!\n", NULL, &data);
	ft_check_twins(&data);
	ft_free_stack(data.a);
	write(1, "\n", 1);
	ft_free_stack(data.b);
	return (0);
}
