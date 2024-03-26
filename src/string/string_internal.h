/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:06 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 18:05:06 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_INTERNAL_H
# define STRING_INTERNAL_H

# include "string.h"

# include <stdlib.h>

typedef struct s_string
{
	size_t	capacity;
	size_t	len;
	char	*arr;
}	t_string;

int	string_resize(t_string *s, size_t min_capacity);

#endif