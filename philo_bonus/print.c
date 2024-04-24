/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:07:16 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/08 22:06:55 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	j = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		x *= 10;
		x += str[i] - '0';
		i++;
	}
	return (x * j);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_single(char **av)
{
	if (ft_strcmp(av[1], "1") == 0)
	{
		printf("0 1 has taken a fork\n");
		usleep(ft_atoi(av[2]));
		printf("%s 1 died\n", av[2]);
		return (1);
	}
	return (0);
}

void	print_state(t_info *info, int i, char *str)
{
	sem_wait(info->print);
	if (!(info->dead))
	{
		printf("%lli ", ft_time() - info->init_time);
		printf("%i ", i + 1);
		printf("%s\n", str);
	}
	sem_post(info->print);
	return ;
}
