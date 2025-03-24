/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:43:07 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/24 03:01:50 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

static void	setup_signal_handler(void);

void		handle_signal(int signum, siginfo_t *info, void *context);

/**
 * @brief Point d'entrée du serveur.
 *
 * Affiche le PID du serveur au démarrage pour que les clients puissent
 * l'utiliser.
 * Configure la gestion des signaux en utilisant setup_signal_handler.
 * Attend indéfiniment les signaux (en utilisant pause et une boucle).
 *
 * @return int Retourne 0 en cas de succès.
 */
int	main(void)
{
	setup_signal_handler();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

/**
 * @brief Gère les signaux entrants.
 *
 * Reçoit les signaux et reconstitue les bits transmis pour former un
 * caractère.
 * Affiche le caractère une fois 8 bits accumulés.
 * Gère également la fin du message lorsqu'un caractère nul est reçu.
 *
 * @param signum Le numéro du signal reçu.
 * @param info Pointeur sur une structure siginfo_t contenant des
 * informations sur le signal.
 * @param context Pointeur sur des informations de contexte.
 */
void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c = (c << 1) | 0;
	else if (signum == SIGUSR2)
		c = (c << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == 0)
		{
			ft_printf("\n");
			client_pid = 0;
		}
		else
			ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
}

/**
 * @brief Configure la gestion des signaux.
 *
 * Configure la gestion des signaux SIGUSR1 et SIGUSR2 en utilisant sigaction.
 * Associe ces signaux à la fonction handle_signal.
 */
static void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	return ;
}
