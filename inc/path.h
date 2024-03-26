/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:40:36 by alletond          #+#    #+#             */
/*   Updated: 2024/03/25 15:40:37 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include <stdbool.h>

# include "ft_error.h"
# include "word_list.h"

typedef struct s_path_info
{
	char	*full_path;
	bool	is_exec;
}	t_path_info;

t_word_list	*path_build_list(char *env_path, char *filename, t_error *error);
t_path_info	path_find(t_word_list *paths);

#endif