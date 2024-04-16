/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:44 by alletond          #+#    #+#             */
/*   Updated: 2024/04/16 17:41:39 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_internal.h"

#include <stdbool.h>
#include <unistd.h>

#include "env.h"
#include "expansion.h"
#include "ft_error.h"
#include "global.h"

int	exec_pipeline(t_ast_node *pipe_node)
{
	int			fd;
	t_pid_list	*pids;
	int			exit_status;

	pids = NULL;
	fd = exec_pipe(pipe_node, &pids, true);
	if (fd >= 0)
		close(fd);
	exit_status = pid_list_wait(pids);
	pid_list_destroy(pids);
	return (exit_status);
}
