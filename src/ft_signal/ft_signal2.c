/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:10:34 by alletond          #+#    #+#             */
/*   Updated: 2024/04/16 14:36:05 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include <readline/readline.h>
#include <signal.h>
#include <termios.h>

#include "libft.h"

void	signal_ignore_sigquit(void)
{
	signal(SIGQUIT, SIG_IGN);
}

void	signal_default_sigquit(void)
{
	signal(SIGQUIT, SIG_DFL);
}
