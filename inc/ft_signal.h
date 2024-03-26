/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:12:38 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:52 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <termios.h>

void	signal_ignore_sigint(void);
void	signal_sigint_replay(void);
void	signal_default_sigint(void);
void	disable_raw_mode(void);
void	enable_raw_mode(void);

#endif