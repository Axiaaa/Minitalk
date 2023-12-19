/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:43:01 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/16 14:02:23 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_control;

void	send_bits(char c, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("\033[1;31mERROR : cant send sig to pid : %d\033[0m\n",
				pid);
			exit(EXIT_FAILURE);
		}
		g_bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_control != 1)
			usleep(10);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bits(str[i], pid);
		i++;
	}
	send_bits(0, pid);
}

void	sig_callback(int sig)
{
	if (sig == SIGUSR1)
		g_bit_control = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("\033[1;32mMessage received !\033[0m\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("\033[1;31mUsage : ./client <pid> <string to send>\033[0m\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sig_callback);
	signal(SIGUSR2, &sig_callback);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("\033[1;31m%s is an invalid pid\033[0m\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	send_str(argv[2], pid);
	while (1)
		sleep(1);
}
