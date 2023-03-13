/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:31:34 by mmarcott          #+#    #+#             */
/*   Updated: 2023/03/13 13:57:37 by mmarcott         ###   ########.fr       */
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
	current = current->next;
	current->nb = value;
}

void    ft_free_stack(t_pile *stack)
{
    t_pile *current;
    t_pile *temp;

    current = stack;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_exit("./push_swap <number> <number> <number>> ...", 1);
	int i;
	t_pile *a;
	a = ft_calloc(1, sizeof(t_pile));
	i = 0;
	while (++i < argc)
		ft_add_value_list(a, ft_atoi(argv[i]));
    t_pile  *current;
    current = a;
	while (current->next)
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
	ft_printf("%d\n", current->nb);
    ft_free_stack(a);
	return (0);
}