/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:40:57 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:40:57 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRINTF_INTERNAL_H
# define FT_SPRINTF_INTERNAL_H

# include <stdarg.h>

int		ft_sprintf_len(char *format, va_list args);
void	ft_sprintf_fill(char *format, va_list args, char *result);

#endif