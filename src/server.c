/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:47 by alakhdar          #+#    #+#             */
/*   Updated: 2022/01/28 10:36:18 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

//Utilisé pour la converison du binaire
int	power_of_two(int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res = res * 2;
		pow--;
	}
	return (res);
}

//Convertir le binaire reçu en char pour pouvoir le print
int	binary_to_char(int *byte)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (byte[i] == 1)
			c += (byte[i] * power_of_two(7 - i));
		i++;
	}
	return (c);
}

//Reçoit les signaux venant du client, et 
//retranscrit en binaire selon le signal reçu
// SIGUSR1 = 1
// SIGUSR2 = 0
void	decrypt_signal(int signal, siginfo_t *info)
{
	static int	byte[8];
	static int	count = 0;
	int			c;

	if (signal == SIGUSR1)
		byte[count++] = 1;
	else if (signal == SIGUSR2)
		byte[count++] = 0;
	if (count == 8)
	{
		c = binary_to_char(byte);
		ft_printf("%c", c);
		kill(info->si_pid, SIGUSR1);
		count = 0;
	}
}

//Pause infinie pour attendre les signaux des clients
int	main(void)
{
	struct sigaction	signal;

	signal.sa_handler = (void *)decrypt_signal;
	signal.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}
