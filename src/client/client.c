/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:54:30 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/24 03:01:04 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

static int	check_args(int argc, char **argv, int *server_pid, char **message);
static void	send_message(int server_pid, const char *message);
static void	send_char(int server_pid, char c);

/**
 * @brief Point d'entrée du client.
 *
 * Vérifie que le nombre d'arguments est correct (attendu : 3
 * arguments), utilise check_args pour convertir argv[1]
 * en PID et récupérer le message. En cas d'erreur, affiche
 * une erreur via ft_error et retourne 1.
 *
 * @param argc Nombre d'arguments passés en ligne de commande.
 * @param argv Tableau de chaînes de caractères, où argv[1] contient
 *             le PID du serveur et argv[2] contient le message à envoyer.
 * @return int Retourne 0 en cas de succès, 1 en cas d'erreur.
 */
int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (check_args(argc, argv, &server_pid, &message))
	{
		ft_error("Erreur: Usage: ./client [PID_serveur] [message]\n");
		return (1);
	}
	send_message(server_pid, message);
	return (0);
}

/**
 * @brief Vérifie et analyse les arguments fournis au programme.
 *
 * Vérifie que argc est égal à 3, convertit argv[1] en un entier pour
 * obtenir le PID du serveur, et assigne argv[2] au message.
 *
 * @param argc Nombre d'arguments (attendu : 3).
 * @param argv Tableau de chaînes de caractères.
 * @param server_pid Pointeur vers un int où le PID converti sera stocké.
 * @param message Pointeur vers un pointeur de chaîne où le message sera stocké.
 * @return int Retourne 0 si les arguments sont valides, 1 sinon.
 */
static int	check_args(int argc, char **argv, int *server_pid, char **message)
{
	if (argc != 3)
		return (1);
	*server_pid = ft_atoi(argv[1]);
	if (*server_pid <= 0)
		return (1);
	*message = argv[2];
	if (!(*message))
		return (1);
	return (0);
}

/**
 * @brief Envoie un message au serveur.
 *
 * Parcourt la chaîne de caractères du message et, pour chaque caractère,
 * appelle send_char pour transmettre ses bits un par un via des signaux.
 * Envoie également le caractère nul ('\0') pour indiquer la fin du message.
 *
 * @param server_pid PID du serveur.
 * @param message Chaîne de caractères terminée par un caractère nul.
 */
void	send_message(int server_pid, const char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
	ft_printf("Message envoyé au serveur (PID: %d)\n", server_pid);
}

/**
 * @brief Envoie un caractère au serveur en transmettant ses 8 bits.
 *
 * Pour chaque bit (du plus significatif au moins significatif),
 * cette fonction envoie SIGUSR2 si le bit est 1, ou SIGUSR1 si le bit est 0.
 * Un court délai (usleep) est utilisé pour permettre au serveur de
 * traiter chaque signal.
 *
 * @param server_pid PID du serveur auquel le caractère est envoyé.
 * @param c Caractère à transmettre.
 */
void	send_char(int server_pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_error("Erreur: Signal SIGUSR2 non envoyé\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_error("Erreur: Signal SIGUSR1 non envoyé\n");
		}
		usleep(100);
		i--;
	}
}
