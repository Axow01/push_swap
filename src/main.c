/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:31:34 by mmarcott          #+#    #+#             */
/*   Updated: 2023/03/13 12:43:13 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_exit(char *message, int code)
{
    ft_printf("Error\n%s\n", message);
    exit(code);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        ft_exit("./push_swap <number> <number> <number>> ...", 1);
    (void)argv;
    return (0);
}