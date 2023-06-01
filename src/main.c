/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:31:34 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/27 19:11:40 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(char *message, int code)
{
	ft_printf("Error\n%s\n", message);
	exit(code);
}

int	ft_add_value_list(t_pile *stack, int value, int who)
{
	t_pile	*current;

	current = stack;
	if (!stack)
	{
		stack = mms_alloc(1, sizeof(t_pile));
		stack->nb = value;
		stack->next = NULL;
		if (who)
			get_data()->a = stack;
		else
			get_data()->b = stack;
		return (1);
	}
	while (current->next)
		current = current->next;
	current->next = mms_alloc(1, sizeof(t_pile));
	current->next->previous = current;
	current = current->next;
	current->nb = value;
	current->next = NULL;
	return (1);
}

void	ft_print_list(t_pile *a)
{
	t_pile	*current;

	if (!a)
		return ;
	current = a;
	while (current->next && current->next != a)
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
	ft_printf("%d\n", current->nb);
}

bool	ft_check_sort()
{
	t_pile	*current;
	int		nb;

	current = get_data()->a;
	nb = current->nb;
	while (current)
	{
		if (current->nb < nb)
			return (false);
		current = current->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		ft_exit("./push_swap <number> <number> <number>> ...", 1);
	mms_set_alloc_fn(ft_calloc);
	data = get_data();
	data->a = NULL;
	data->b = mms_alloc(1, sizeof(t_pile));
	if (!data->b || ft_parsing(argv, argc, data) == 0)
		ft_exit_pointer("Calloc error or parsing!\n", NULL, data);
	ft_check_twins(data);
	ft_sort();
	mms_kill(NULL, true, EXIT_SUCCESS);
	return (0);
}
