/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:00:13 by yuxchen           #+#    #+#             */
/*   Updated: 2024/02/21 18:39:07 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

int		get_line_len(t_list *list);
void	get_line(t_list *list, char *next_line);
bool	find_next_line(t_list *list);
void	append_buf(int fd, t_list **list, char *buf);
t_list	*find_last_node(t_list *list);
void	clean_list(t_list **list, t_list *new_node, char *new_buf);
void	new_list(t_list **list);
char	*read_line(t_list *list);
void	create_list(int fd, t_list **list);
char	*get_next_line(int fd);

#endif
