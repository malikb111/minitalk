/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:47:37 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/18 12:47:46 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/**
 * @brief Sends a message to the server identified by server_pid.
 *
 * For each character in the message, the function calls send_char
 * to transmit each bit via the SIGUSR1 and SIGUSR2 signals.
 */
void	send_message(int server_pid, const char *message);

/**
 * @brief Sends a character to the server identified by server_pid, bit by bit.
 *
 * Each bit is sent as a signal: SIGUSR1 for a 0 bit and SIGUSR2 for a 1 bit.
 */
void	send_char(int server_pid, char c);

/**
 * @brief Handles signals for the server.
 *
 * Reconstructs received bits into a complete character.
 * Once 8 bits are accumulated, the character is displayed.
 * Also handles the end of the message when a null character is received.
 */
void	handle_signal(int signum, siginfo_t *info, void *context);

#endif