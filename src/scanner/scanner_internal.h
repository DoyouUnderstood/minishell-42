/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:02:09 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 18:02:09 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_INTERNAL_H
# define SCANNER_INTERNAL_H

typedef struct s_scanner
{
	char	*src;
	int		start;
	int		current;
}	t_scanner;

t_scanner	*scanner_create(char *src);

#endif