/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:45:30 by abbouras          #+#    #+#             */
/*   Updated: 2025/03/20 12:22:52 by abbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

/**
 * @brief Affiche un message d'erreur sur stderr et termine le programme.
 *
 * Cette fonction gère les erreurs fatales, par exemple :
 * - Argument invalide
 * - Appel kill échoué
 *
 * @param error_message Le message d'erreur à afficher.
 */
void	ft_error(const char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(1);
}
