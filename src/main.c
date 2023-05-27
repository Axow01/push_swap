/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:31:34 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/07 02:38:22 by mmarcott         ###   ########.fr       */
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
	if (!current)
		return (0);
	while (current->next)
		current = current->next;
	current->next = mms_alloc(1, sizeof(t_pile));
	if (!current->next)
		return (0);
	current->next->previous = current;
	current = current->next;
	current->nb = value;
	current->next = NULL;
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
		temp = current;
		current = current->next;
		temp = ft_free(temp);
	}
	current = ft_free(current);
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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		ft_exit("./push_swap <number> <number> <number>> ...", 1);
	data = get_data();
	// data->a = ft_calloc(1, sizeof(t_pile));
	data->a = NULL;
	data->b = mms_alloc(1, sizeof(t_pile));
	if (!data->b || ft_parsing(argv, argc, data) == 0)
		ft_exit_pointer("Calloc error or parsing!\n", NULL, data);
	ft_check_twins(data);
	ft_sort();
	mms_kill(NULL, true, EXIT_SUCCESS);
	return (0);
}
