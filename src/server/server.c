#include "../../include/minitalk.h"
// Prototypes pour les fonctions du serveur

/*
** main:
** Point d'entrée du serveur.
** - Affiche le PID du serveur dès le lancement afin que le client puisse l'utiliser.
** - Configure la gestion des signaux via setup_signal_handler.
** - Attend indéfiniment les signaux (via pause ou une boucle).
*/
int	main(void)
{
	return (0);
}

/*
** setup_signal_handler:
** Configure le traitement des signaux SIGUSR1 et SIGUSR2 en utilisant sigaction.
** - Associe les signaux à la fonction handle_signal.
*/
static void	setup_signal_handler(void)
{
	// Implementation of setup_signal_handler function
}

/*
** handle_signal:
** Fonction de gestion des signaux.
** - Reçoit les signaux et recompose les bits transmis pour former un caractère.
** - Affiche le caractère lorsque 8 bits ont été accumulés.
** - Gère également la fin du message (lorsqu'un caractère nul est reçu).
*/
void	handle_signal(int signum, siginfo_t *info, void *context)
{
	// Implementation of handle_signal function
}