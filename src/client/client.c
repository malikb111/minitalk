/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:54:30 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/18 12:37:14 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**
 * @brief Client entry point.
 *
 * Checks that the number of arguments is correct (expected: 3
 * arguments), uses validate_arguments to convert argv[1]
 * to a PID and retrieve the message. In case of error, displays
 * an error via ft_error and returns 1.
 *
 * @param argc Number of arguments passed in the command line.
 * @param argv Array of strings, where argv[1] contains
 *             the server's PID and argv[2] contains the message to send.
 * @return int Returns 0 on success, 1 on error.
 */
int	main(int argc, char **argv)
{
	return (0);
}

/**
 * @brief Checks and parses the arguments provided to the program.
 *
 * Verifies that argc is equal to 3, converts argv[1] to an integer to
 * obtain the server PID, and assigns argv[2] to the message.
 *
 * @param argc Number of arguments (expected: 3).
 * @param argv Array of strings.
 * @param server_pid Pointer to an int where the converted PID will be stored.
 * @param message Pointer to a string pointer where the message will be stored.
 * @return int Returns 0 if the arguments are valid, 1 otherwise.
 */
static int	validate_arguments(int argc, char **argv, int *server_pid,
		char **message)
{
	return (0);
}

/**
 * @brief Sends a message to the server.
 *
 * Iterates over the message string and, for each character,
 * calls send_char to transmit its bits one by one via signals.
 * Also sends the null character ('\0') to indicate the end of the message.
 *
 * @param server_pid Server PID.
 * @param message Null-terminated string.
 */
void	send_message(int server_pid, const char *message)
{
	return ;
}

/**
 * @brief Sends a character to the server by transmitting its 8 bits.
 *
 * For each bit (from the most significant to the least significant),
 * this function sends SIGUSR2 if the bit is 1, or SIGUSR1 if the bit is 0.
 * A short pause (usleep) is used to allow the server time to
 * process each signal.
 *
 * @param server_pid PID of the server to which the character is sent.
 * @param c Character to transmit.
 */
void	send_char(int server_pid, char c)
{
	return ;
}
