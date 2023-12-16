/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:43:21 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/15 11:43:21 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "../libft/libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *));

#endif
