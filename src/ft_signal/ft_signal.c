/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:10:23 by alletond          #+#    #+#             */
/*   Updated: 2024/04/16 18:45:15 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include <readline/readline.h>
#include <signal.h>
#include <termios.h>

#include "libft.h"
#include "global.h"

void	signal_ignore_sigint(void)
{
	signal(SIGINT, SIG_IGN);
}

void	replay_sigint_handler(int sig)
{
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	last_exit_status(1);
	(void)sig;
}

void	signal_sigint_replay(void)
{
	signal(SIGINT, replay_sigint_handler);
}

void	signal_default_sigint(void)
{
	signal(SIGINT, SIG_DFL);
}
