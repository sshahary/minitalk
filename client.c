/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:38:10 by sshahary          #+#    #+#             */
/*   Updated: 2023/11/29 16:11:56 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	r;
	int	i;
	int	s;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * s);
}

void	send_msg(int PID, char *str)
{
	int	i;

	if (!PID || !str)
		return ;
	while (*str)
	{
		i = 7;
		while (i + 1)
		{
			if (*str & (1 << i))
				kill(PID, SIGUSR1);
			else
				kill(PID, SIGUSR2);
			i--;
			usleep(50);
		}
		str++;
		usleep(50);
	}
}

int	main(int ac, char *argv[])
{
	int		p;
	char	*s;

	if (ac != 3 || !(ft_strlen(argv[2])))
		return (1);
	p = ft_atoi(argv[1]);
	s = argv[2];
	send_msg(p, s);
	return (0);
}
