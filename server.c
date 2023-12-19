/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:42:43 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/16 14:04:50 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("ERROR : cant send sig to pid : %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		ft_printf("\n\033[1;36mReceied from Client : \033[0m");
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_putchar_fd(c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	init_sig(SIGUSR1, &sig_handler);
	init_sig(SIGUSR2, &sig_handler);
	ft_printf("\033[1;33mServer PID: %d\033[0m\n", getpid());
	while (1)
		sleep(1);
}
