/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:56 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:03:52 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "expansion_internal.h"

#include "global.h"
#include "hash_map.h"
#include "libft.h"
#include "scanner.h"
#include "word_list.h"

/** Extract a segment from the scanner.
 * 
 * Returns 0 on success, or -1 on error.
*/
int	extract_segment(t_scanner *scanner, t_word_list **segments)
{
	char	*extracted;
	int		result;

	extracted = scanner_extract(scanner);
	if (!extracted)
		return (-1);
	result = word_list_add(segments, extracted);
	free(extracted);
	return (result);
}

/** Handles a quote in the parameter value.
 * 
 * Returns 0 on success, or -1 on error.
*/
static int	handle_param_value_quote(t_scanner *scanner,
	t_word_list **segments)
{
	int	status;

	status = 0;
	if (extract_segment(scanner, segments) != 0)
		return (-1);
	if (scanner_match(scanner, "'"))
		status = word_list_add(segments, "\"'\"");
	else if (scanner_match(scanner, "\""))
		status = word_list_add(segments, "'\"'");
	scanner_skip(scanner);
	return (status);
}

/** Adds the parameter value to the segment list.
 * 
 * If the parameter value contains any single quotes, they are surrounded
 * by double quotes before adding, and conversely with double quotes.
 * 
 * Returns 0 on success, or -1 on error.
*/
static int	add_param_value(char *param_value, t_word_list **segments)
{
	int			status;
	t_scanner	*scanner;

	scanner = scanner_create(param_value);
	status = 0;
	if (!scanner)
		return (-1);
	while (!scanner_is_at_end(scanner))
	{
		if (scanner_check(scanner, '\'') || scanner_check(scanner, '"'))
			status = handle_param_value_quote(scanner, segments);
		else
			scanner_advance_until(scanner, "'\"");
		if (status != 0)
			break ;
	}
	if (status == 0)
		status = extract_segment(scanner, segments);
	scanner_destroy(scanner);
	return (status);
}

static int	add_last_exit_status(t_scanner *scanner, t_word_list **segments)
{
	char	*status_str;

	scanner_skip(scanner);
	status_str = ft_itoa(last_exit_status(-1));
	if (!status_str)
		return (-1);
	if (word_list_add(segments, status_str) != 0)
	{
		free(status_str);
		return (-1);
	}
	free(status_str);
	return (0);
}

/** Extracts the characters already traversed,
 * then extracts the parameter value.
 * 
 * Return 0 on success, or -1 on error.
*/
int	extract_param(t_scanner *scanner, t_word_list **segments,
	t_hash_map *env)
{
	char	*param_key;
	char	*param_value;

	if (extract_segment(scanner, segments) != 0)
		return (-1);
	if (!scanner_match(scanner, "$"))
		return (0);
	scanner_skip(scanner);
	if (scanner_match(scanner, "?"))
		return (add_last_exit_status(scanner, segments));
	if (!ft_strchr("_" EXP_LETTERS, scanner_peek(scanner)))
		return (0);
	scanner_advance_while(scanner, "_" EXP_LETTERS);
	scanner_advance_while(scanner, "_" EXP_LETTERS EXP_NUMBERS);
	param_key = scanner_extract(scanner);
	if (!param_key)
		return (-1);
	param_value = NULL;
	if (*param_key)
		param_value = hash_map_get(env, param_key);
	free(param_key);
	if (param_value && *param_value)
		return (add_param_value(param_value, segments));
	return (0);
}
