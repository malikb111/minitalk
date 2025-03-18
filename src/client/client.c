/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:54:30 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/18 12:00:21 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"
// Prototypes pour les fonctions du client

/* 
** main:
** Point d'entrée du client.
** - Valide les arguments de la ligne de commande (doit recevoir le PID du serveur et le message).
** - Convertit le PID au format entier.
** - Appelle send_message pour envoyer le message au serveur.
*/
int	main(int argc, char **argv)
{
	return (0);
}

/*
** validate_arguments:
** Vérifie et analyse les arguments passés au programme.
** - S'assure que le nombre d'arguments est correct.
** - Convertit le PID du serveur (argument 1) en entier.
** - Récupère le message (argument 2).
** Retourne 0 si tout est correct, sinon une valeur différente pour signaler une erreur.
*/
static int	validate_arguments(int argc, char **argv, int *server_pid, char **message)
{
	return (0);
}

/*
** send_message:
** Parcourt la chaîne de caractères et envoie chaque caractère au serveur.
** Pour chaque caractère, fait appel à send_char afin de transmettre les bits un par un.
*/
void	send_message(int server_pid, const char *message)
{
	return ;
}

/*
** send_char:
** Envoie un caractère au serveur en transmettant ses 8 bits.
** - Utilise SIGUSR1 lorsque le bit est à 0 et SIGUSR2 lorsque le bit est à 1.
*/
void	send_char(int server_pid, char c)
{
	return ;
}