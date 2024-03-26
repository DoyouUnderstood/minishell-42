/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:01:39 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 18:01:53 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "scanner_internal.h"

#include <stdbool.h>

#include "libft.h"

/** Returns the current character and moves current forward.
 * 
 * If current is at the end, doesn't move forward.
*/
char	scanner_advance(t_scanner *scanner)
{
	char	c;

	c = scanner_peek(scanner);
	if (!scanner_is_at_end(scanner))
		scanner->current++;
	return (c);
}

/** Moves current forward until the current character is in delim.
 * 
 * Returns the number of characters that were traversed.
*/
int	scanner_advance_until(t_scanner *scanner, char *delim)
{
	int	count;

	count = 0;
	while (!scanner_is_at_end(scanner)
		&& !ft_strchr(delim, scanner_peek(scanner)))
	{
		scanner->current++;
		count++;
	}
	return (count);
}

/** Moves current forward while current character is in chars.
 * 
 * Returns the number of characters traversed.
*/
int	scanner_advance_while(t_scanner *scanner, char *chars)
{
	int	count;

	count = 0;
	while (!scanner_is_at_end(scanner)
		&& ft_strchr(chars, scanner_peek(scanner)))
	{
		scanner->current++;
		count++;
	}
	return (count);
}
