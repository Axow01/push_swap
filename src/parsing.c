/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:02:03 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/24 15:02:03 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_arguments(char **args, int argc, bool main_args)
{
	int			i;
	int			k;
	long int	nb;

	i = -1;
	nb = 0;
	if (main_args)
		i = 0;
	while (++i < argc)
	{
		k = -1;
		while (args[i][++k])
			if (!ft_isdigit((int)args[i][k])
				&& !(args[i][k] == '-' && ft_isdigit((int)args[i][k + 1])))
				return (0);
		if (ft_strlen(args[i]) > 11)
			return (0);
		nb = ft_atoli(args[i]);
		if ((nb > INT_MAX || nb < INT_MIN))
			return (0);
	}
	return (1);
}

// int	ft_check_args(char **args, int argc, int o)
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	k = 0;
// 	if (o == 0)
// 		i = -1;
// 	while (++i < argc)
// 	{
// 		k = -1;
// 		while (args[i][++k])
// 			if (!ft_isdigit((int)args[i][k]) && (args[i][k] == '-'
// 					&& !ft_isdigit(args[i][k + 1])))
// 				return (0);
// 	}
// 	return (1);
// }

/* Transform an double array to integer and puts them inside data->a. */
void	ft_transform(char **numbers, int c, t_data *data, int o)
{
	int	i;

	i = 0;
	if (o == 0)
		i = -1;
	while (++i < c)
		if (!ft_add_value_list(data->a, (int)ft_atoli(numbers[i]), 1))
			ft_exit_pointer("Calloc error!\n", NULL, data);
}

int	ft_len_double(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}

void	ft_free_double(char **pointer)
{
	int	i;

	i = -1;
	while (pointer[++i])
		pointer[i] = ft_free(pointer[i]);
	pointer = ft_free(pointer);
}

int	ft_parsing(char **args, int argc, t_data *data)
{
	char	**numbers;

	if (!ft_check_arguments(args, argc, true) && argc != 2)
		return (0);
	if (argc == 2)
	{
		numbers = ft_split(args[1], ' ');
		if (!numbers)
			return (0);
		if (!ft_check_arguments(numbers, ft_len_double(numbers), false))
		{
			ft_free_double(numbers);
			return (0);
		}
		ft_transform(numbers, ft_len_double(numbers), data, 0);
		ft_free_double(numbers);
	}
	else
		ft_transform(args, argc, data, 1);
	return (1);
}
