/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:43:07 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/18 12:43:38 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**
 * @brief Server entry point.
 *
 * Displays the server PID at startup so that clients can use it.
 * Sets up signal handling using setup_signal_handler.
 * Waits indefinitely for signals (using pause or a loop).
 *
 * @return int Returns 0 on success.
 */
int	main(void)
{
	return (0);
}

/**
 * @brief Configures signal handling.
 *
 * Sets up the handling of SIGUSR1 and SIGUSR2 signals using sigaction.
 * Associates these signals with the handle_signal function.
 */
static void	setup_signal_handler(void)
{
	return ;
}

/**
 * @brief Handles incoming signals.
 *
 * Receives signals and reassembles the transmitted bits to form a character.
 * Displays the character once 8 bits have been accumulated.
 * Also manages the end of the message when a null character is received.
 *
 * @param signum The signal number received.
 * @param info Pointer to a siginfo_t structure containing signal information.
 * @param context Pointer to context information.
 */
void	handle_signal(int signum, siginfo_t *info, void *context)
{
	return ;
}
