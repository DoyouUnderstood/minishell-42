/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:19 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:07:39 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_INTERNAL_H
# define EXPANSION_INTERNAL_H

# include "scanner.h"
# define EXP_LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define EXP_NUMBERS "0123456789"

int	extract_param(t_scanner *scanner, t_word_list **segments,
		t_hash_map *env);
int	extract_segment(t_scanner *scanner, t_word_list **segments);
#endif