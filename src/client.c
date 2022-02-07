/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:38 by alakhdar          #+#    #+#             */
/*   Updated: 2022/01/28 13:29:02 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

unsigned long	g_len = 0;

//Convertit les char en binaire pour pouvoir
//les envoyer via les signaux UNIX
void	char_to_binary(char c, char *ret)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (c % 2 == 0)
			ret[i] = '0';
		else
			ret[i] = '1';
		c /= 2;
		i--;
	}
}

//Envoie la chaine sous forme binaire grâce aux signaux UNIX
// SIGUSR1 = le byte sera un 1
// SIGUSR2 = le byte sera un 0
void	send_string(int pid, char *str)
{
	int		i;
	char	*c;
	int		j;

	i = 0;
	while (str[i])
	{
		c = malloc(sizeof(char) * 8);
		if (!c)
			return ;
		char_to_binary(str[i], c);
		j = 0;
		while (c[j])
		{
			if (c[j] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(500);
		}
		free(c);
		i++;
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		g_len++;
}

//Dispatche la string dans le sender, et retourne
//un accusé de réception quand g_len est de même taille que l'arg (BONUS)
int	main(int ac, char **av)
{
	signal(SIGUSR1, handle_signal);
	if (ac == 3)
	{
		send_string(ft_atoi(av[1]), "\n");
		send_string(ft_atoi(av[1]), av[2]);
	}
	else
	{
		ft_printf("INVALID ARGUMENTS\n");
		return (0);
	}
	if (g_len == ft_strlen(av[2]) + 1)
		ft_printf("\nMESSAGE RECEIVED\n\n");
	return (0);
}
