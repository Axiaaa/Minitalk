/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:15:14 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/16 15:15:14 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sigact;

	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&sigact.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &sigact, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &sigact, 0);
}
