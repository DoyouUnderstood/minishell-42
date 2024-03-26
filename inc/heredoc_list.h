/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:40:04 by alletond          #+#    #+#             */
/*   Updated: 2024/03/25 15:40:05 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_LIST_H
# define HEREDOC_LIST_H

# include "redir_list.h"

typedef struct s_heredoc_list
{
	struct s_heredoc_list	*next;
	t_redir_list			*heredoc_node;
}	t_heredoc_list;

int				heredoc_list_add(t_heredoc_list **list,
					t_redir_list *heredoc_node);
void			heredoc_list_destroy(t_heredoc_list *list);
t_heredoc_list	*heredoc_list_last(t_heredoc_list *list);
void			heredoc_list_close_all(t_heredoc_list *list);
int				heredoc_list_read(t_heredoc_list *list);

#endif