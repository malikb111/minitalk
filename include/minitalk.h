/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:47:37 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/20 12:26:38 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../external/libft/libft.h"

void	send_message(int server_pid, const char *message);
void	send_char(int server_pid, char c);
void	handle_signal(int signum, siginfo_t *info, void *context);

#endif