/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_build_list_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:50:05 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:50:06 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_BUILD_LIST_INTERNAL_H
# define PATH_BUILD_LIST_INTERNAL_H

# include <stdbool.h>

# include "ft_error.h"
# include "scanner.h"
# include "word_list.h"

char		*build_full_path(char *prefix, char *filename, t_error *error);
char		*add_current_dir(t_scanner *scanner, char *filename,
				bool *added_current, t_error *error);
char		*next_full_path(t_scanner *scanner, char *filename,
				bool *added_current, t_error *error);
t_word_list	*path_build_list_no_slash(char *env_path, char *filename,
				t_error *error);

#endif