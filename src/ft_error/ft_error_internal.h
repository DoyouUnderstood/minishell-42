/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:08:26 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:09:40 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_INTERNAL_H
# define FT_ERROR_INTERNAL_H

# include "ft_error.h"

typedef enum e_error_type
{
	ERR_NONE,
	ERR_SYSTEM,
	ERR_CUSTOM
}	t_error_type;

struct s_error
{
	t_error_type	type;
	int				code;
	char			*msg;
};

#endif