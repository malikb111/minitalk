/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <votrelogin> <votremail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:54:30 by <votrelogin>     #+#    #+#             */
/*   Updated: 2025/03/18 11:54:30 by <votrelogin>    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** send_message:
** Envoie une chaîne de caractères terminée par '\0' au serveur identifié par server_pid.
** Pour chaque caractère de la chaîne, la fonction appelle send_char afin de transmettre
** chaque bit via les signaux SIGUSR1 et SIGUSR2.
*/
void	send_message(int server_pid, const char *message);

/*
** send_char:
** Envoie un caractère au serveur spécifié par server_pid, bit par bit.
** Chaque bit est envoyé sous forme de signal : SIGUSR1 pour un bit à 0 et SIGUSR2 pour un bit à 1.
*/
void	send_char(int server_pid, char c);

/*
** handle_signal:
** Fonction de gestion des signaux pour le serveur.
** Reconstitue les bits reçus via les signaux en un caractère complet.
** Une fois 8 bits accumulés, le caractère est affiché.
** La fonction gère également la fin du message lorsque le caractère nul ('\0') est reçu.
*/
void	handle_signal(int signum, siginfo_t *info, void *context);


#endif