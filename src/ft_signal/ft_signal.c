/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:10 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:15:56 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_signal.h"
#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <string.h>

// struct termios orig_termios;
// volatile sig_atomic_t heredoc_interrupted = 0;

// void sigintHeredocHandler(int signum) {

//     heredoc_interrupted = 1;
//     (void)signum;
// }

// void disable_raw_mode() {
//     tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
// }

// void enable_raw_mode() {
//     tcgetattr(STDIN_FILENO, &orig_termios);
//     atexit(disable_raw_mode);
//     struct termios raw = orig_termios;
//     raw.c_lflag &= ~(ECHOCTL);
//     tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
// }

// // Cette fonction gère les interruptions du user (Ctrl+C) dans le shell.
// void sigintHandler(int sig) {
//     printf("\n");
//     rl_on_new_line();
//     rl_replace_line("", 0);
//     rl_redisplay();
//     (void)sig;
// }

// // Configuration des signaux pour le shell.
// void setupSignals() 
// {
//     struct sigaction sa;
//     sa.sa_handler = sigintHandler;
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = SA_RESTART;
//     sigaction(SIGINT, &sa, NULL);
// }

// void resetSignalsForExec() {
//     signal(SIGINT, SIG_DFL);
// }

// // Cette fonction gère les interruptions pendant la lecture d'un heredoc.
// void sigintHandlerHeredoc(int sig) {
//     heredoc_interrupted = 1;
//     printf("Heredoc interrupted.\n");
//     rl_replace_line("", 0);
//     rl_redisplay();
//     (void)sig;
// }

// void restoreDefaultSignals() {
//     struct sigaction sa;

//     sa.sa_handler = SIG_DFL;
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = 0;

//     sigaction(SIGINT, &sa, NULL);
// }

// // Configuration des signaux spécifiques pour les heredocs.
// void setupHeredocSignals() {
//     signal(SIGINT, sigintHandler);
// }