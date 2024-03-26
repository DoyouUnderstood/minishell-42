/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:30 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 16:40:30 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_internal.h"

#include "ft_error.h"
#include "global.h"

int	handle_system_error(char *word, bool should_exit)
{
	ft_error_print_system(prog_name(NULL), word);
	if (should_exit)
		exit(1);
	return (1);
}

int	handle_ambiguous_redirect(char *word, bool should_exit)
{
	ft_error_print_custom(prog_name(NULL), word, "ambiguous redirect");
	if (should_exit)
		exit(1);
	return (1);
}

int	handle_cmd_not_found(char *word, bool should_exit)
{
	ft_error_print_custom(prog_name(NULL), word, "command not found");
	if (should_exit)
		exit(127);
	return (127);
}

int	handle_permission_denied(char *word, bool should_exit)
{
	ft_error_print_custom(prog_name(NULL), word, "Permission denied");
	if (should_exit)
		exit(126);
	return (126);
}
