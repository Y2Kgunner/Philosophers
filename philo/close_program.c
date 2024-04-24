/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:43:30 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/09 13:34:00 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char **c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (c[i] != NULL)
	{
		j = 0;
		while (c[i][j] != '\0')
		{
			if (c[i][j] >= '0' && c[i][j] <= '9')
				j++;
			else
			{
				printf("WRONG ARGUMENTS");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	if (av[5])
	{
		if (ft_atoi(av[5]) <= 0)
		{
			printf("WRONG ARGUMENTS");
			return (1);
		}
	}
	if (ft_isdigit(av))
		return (1);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 \
		|| ft_atoi(av[4]) < 0 || ft_atoi(av[1]) > 200)
	{
		printf("WRONG ARGUMENTS");
		return (1);
	}
	return (0);
}

void	destroy_mutex(t_info *destroy, t_phils *phils)
{
	int	i;

	i = 0;
	while (i < destroy->n_philos)
	{
		pthread_join(phils[i].tid, NULL);
		i++;
	}
	i = 0;
	while (i < destroy->n_philos)
	{
		pthread_mutex_destroy(&(destroy->forks[i]));
		pthread_detach(phils[i].tid);
		i++;
	}
	pthread_mutex_destroy(&(destroy->print));
	pthread_mutex_destroy(&(destroy->meals));
}
