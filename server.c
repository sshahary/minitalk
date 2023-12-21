/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:57:53 by sshahary          #+#    #+#             */
/*   Updated: 2023/11/29 15:56:07 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	handler(int signal)
{
	static int	bit = 0;
	static int	i;
	char		c;

	if (signal == SIGUSR1)
	{
		bit = bit << 1;
		bit = bit | 1;
	}
	if (signal == SIGUSR2)
	{
		bit = bit << 1;
	}
	i++;
	if (i == 8)
	{
		c = (char)bit;
		write(1, &c, 1);
		bit = 0;
		i = 0;
	}
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr / 10 > 0)
	{
		ft_putnbr(nbr / 10);
	}
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	if (!(signal(SIGUSR1, handler) || !(signal(SIGUSR2, handler))))
		return (-1);
	while (1)
		pause();
	return (0);
}
