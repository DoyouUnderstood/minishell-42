/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:02:03 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 18:03:51 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "scanner_internal.h"

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"
/** Creates a new character scanner.
 * 
 * src is the string to scan, and should not be NULL.
 * 
 * Returns the scanner, or NULL on error.
*/
t_scanner	*scanner_create(char *src)
{
	t_scanner	*scanner;

	scanner = malloc(sizeof(*scanner));
	if (!scanner)
		return (NULL);
	scanner->start = 0;
	scanner->current = 0;
	scanner->src = ft_strdup(src);
	if (!scanner->src)
	{
		free(scanner);
		return (NULL);
	}
	return (scanner);
}
