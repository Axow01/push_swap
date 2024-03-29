/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mms.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:51:32 by mmarcott          #+#    #+#             */
/*   Updated: 2023/07/24 13:06:06 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmms.h"

// Note: add protection later.
t_pointer	*get_data_mms(void)
{
	static t_pointer	*data = NULL;

	if (!data)
	{
		data = ft_calloc(1, sizeof(t_pointer));
		if (!data)
			mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
		data->f = ft_calloc;
	}
	return (data);
}

void	mms_kill(char *message, bool quit, int code)
{
	t_pointer	*current;
	t_pointer	*buffer;

	current = get_data_mms();
	while (current)
	{
		if (current->ptr)
			free(current->ptr);
		current->ptr = NULL;
		buffer = current->next;
		free(current);
		current = buffer;
	}
	if (message)
		ft_putstr_fd("Error\n", 2);
	if (quit)
		exit(code);
	(void)message;
}

void	*mms_alloc(size_t size, size_t typesize)
{
	t_pointer	*current;
	void		*p;

	if (size <= 0)
		size = 1;
	if (!get_data_mms()->ptr)
	{
		p = get_data_mms()->f(size, typesize);
		get_data_mms()->ptr = p;
		if (!get_data_mms()->ptr)
			mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
		get_data_mms()->next = NULL;
		return (get_data_mms()->ptr);
	}
	current = get_data_mms();
	while (current->next)
		current = current->next;
	current->next = get_data_mms()->f(1, sizeof(t_pointer));
	if (!current->next)
		mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
	current->next->ptr = get_data_mms()->f(size, typesize);
	if (!current->next->ptr)
		mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
	current->next->next = NULL;
	return (current->next->ptr);
}

void	*mms_free(void *ptr)
{
	t_pointer	*current;

	if (!ptr)
		return (NULL);
	current = get_data_mms();
	while (current)
	{
		if (current->ptr == ptr)
		{
			free(current->ptr);
			current->ptr = NULL;
			return (NULL);
		}
		current = current->next;
	}
	return (NULL);
}
