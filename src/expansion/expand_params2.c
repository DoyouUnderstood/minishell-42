/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_params2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:55:17 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:04:50 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "expansion_internal.h"

#include "global.h"
#include "hash_map.h"
#include "libft.h"
#include "scanner.h"
#include "word_list.h"

/** Loops over characters in scanner, and extracts the segments
 * 
 * Returns 0 on success, or -1 on error.
*/
static int	loop_src(t_scanner *scanner, t_word_list **segments,
	t_hash_map *env)
{
	bool	in_dbl_quotes;
	bool	in_sgl_quotes;

	in_dbl_quotes = false;
	in_sgl_quotes = false;
	while (!scanner_is_at_end(scanner))
	{
		if (!in_sgl_quotes && scanner_check(scanner, '$'))
		{
			if (extract_param(scanner, segments, env) != 0)
				return (-1);
		}
		else
		{
			if (!in_dbl_quotes && scanner_check(scanner, '\''))
				in_sgl_quotes = !in_sgl_quotes;
			if (!in_sgl_quotes && scanner_check(scanner, '"'))
				in_dbl_quotes = !in_dbl_quotes;
			scanner_advance(scanner);
		}
	}
	if (extract_segment(scanner, segments) != 0)
		return (-1);
	return (0);
}

/** Replaces environment variables in a string.
 * 
 * Replaces any valid variable name outside single quotes
 * in the source string by the environment value (if found);
 * 
 * Returns the expanded string, or NULL on error.
*/
char	*expand_params(char *s, t_hash_map *env)
{
	char		*expanded;
	t_word_list	*segments;
	t_scanner	*scanner;

	segments = NULL;
	scanner = scanner_create(s);
	if (!scanner)
		return (NULL);
	if (loop_src(scanner, &segments, env) != 0)
	{
		scanner_destroy(scanner);
		word_list_destroy(segments);
		return (NULL);
	}
	scanner_destroy(scanner);
	expanded = word_list_to_str(segments);
	word_list_destroy(segments);
	return (expanded);
}

/** Replaces environment variables in a string and split the string
 * into words using whitespace.
 * 
 * Replaces any valid variable name outside single quotes
 * in the source string by the environment value (if found);
 * 
 * Returns the list of expanded and split words, or NULL on error.
*/
t_word_list	*expand_params_split(char *s, t_hash_map *env)
{
	char		*expanded;
	t_word_list	*words;

	expanded = expand_params(s, env);
	if (!expanded)
		return (NULL);
	words = expand_split_words(expanded);
	free(expanded);
	return (words);
}
