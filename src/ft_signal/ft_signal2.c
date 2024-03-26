/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:10:23 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:39:50 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include <readline/readline.h>
#include <signal.h>
#include <termios.h>

#include "libft.h"

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

void	disable_raw_mode(void)
{
	struct termios	tp;

	tcgetattr(STDIN_FILENO, &tp);
	tp.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp);
}
