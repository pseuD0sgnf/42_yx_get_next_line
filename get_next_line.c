/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:06:31 by yuxchen           #+#    #+#             */
/*   Updated: 2024/02/21 18:39:00 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_list(t_list **list, t_list *new_node, char *new_buf)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	if (new_buf[0])
	{
		new_node->buffer = new_buf;
		new_node->next = NULL;
		*list = new_node;
	}
	else
	{
		free(new_buf);
		free(new_node);
		*list = NULL;
	}
}

void	new_list(t_list **list)
{
	t_list	*new_node;
	t_list	*last_node;
	char	*new_buf;
	int		i;
	int		j;

	if (!list)
		return ;
	new_buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!new_buf || !new_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i++])
		new_buf[j++] = last_node->buffer[i];
	new_buf[j] = '\0';
	clean_list(list, new_node, new_buf);
}

char	*read_line(t_list *list)
{
	char	*next_line;
	int		next_line_len;

	if (!list)
		return (NULL);
	next_line_len = get_line_len(list);
	next_line = malloc(next_line_len + 1);
	if (!next_line)
		return (NULL);
	get_line(list, next_line);
	return (next_line);
}

void	create_list(int fd, t_list **list)
{
	char	*buf;
	int		buf_bytes;

	while (!find_next_line(list[fd]))
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return ;
		buf_bytes = read(fd, buf, BUFFER_SIZE);
		if (buf_bytes <= 0)
		{
			free(buf);
			return ;
		}
		buf[buf_bytes] = '\0';
		append_buf(fd, list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	create_list(fd, list);
	if (!list[fd])
		return (NULL);
	next_line = read_line(list[fd]);
	new_list(&list[fd]);
	return (next_line);
}

// # include <fcntl.h>

// int main()
// {
//     int     fd1;
//     char    *line;
//     int     lines;

//     lines = 1;
//     fd1 = open("test1.txt", O_RDONLY);
//     while(line = get_next_line(fd1))
// 	{
// 		printf("%d -> %s\n", lines++, line);
// 		free(line);
// 	}
// }
