/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:56 by alakhdar          #+#    #+#             */
/*   Updated: 2022/01/28 10:38:25 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_itoa(int n);
int		ft_atoi(char *str);

#endif
