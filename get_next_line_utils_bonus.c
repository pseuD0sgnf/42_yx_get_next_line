/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:00:28 by yuxchen           #+#    #+#             */
/*   Updated: 2024/02/21 18:59:23 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	get_line(t_list *list, char *next_line)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				next_line[j] = '\n';
				next_line[++j] = '\0';
				return ;
			}
			next_line[j++] = list->buffer[i++];
		}
		list = list->next;
	}
	next_line[j] = '\0';
}

int	get_line_len(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (false);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			len++;
			if (list->buffer[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	append_buf(int fd, t_list **list, char *buf)
{
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	last_node = find_last_node(list[fd]);
	if (!last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buf;
	new_node->next = NULL;
}

bool	find_next_line(t_list *list)
{
	int	i;

	if (!list)
		return (false);
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
				return (true);
			i++;
		}
		list = list->next;
	}
	return (false);
}
