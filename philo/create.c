/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:15:42 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/13 17:14:05 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo_struct(t_info *info)
{
	int	pos;

	pos = 0;
	while (pos < info->n_philos)
	{
		info->phils[pos].philo_id = pos;
		info->phils[pos].if_ate = 0;
		info->phils[pos].l_fork = pos;
		info->phils[pos].r_fork = (pos + 1) % info->n_philos;
		info->phils[pos].eat_gap = 0;
		info->phils[pos].info = info;
		pos++;
	}
}

static void	ft_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philos)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(info->print), NULL);
	pthread_mutex_init(&(info->meals), NULL);
}

void	init_main(t_info *info, char **av)
{
	info->ate = 0;
	info->dead = 0;
	info->n_philos = ft_atoi(av[1]);
	info->ttd = ft_atoi(av[2]);
	info->tte = ft_atoi(av[3]);
	info->tts = ft_atoi(av[4]);
	if (av[5])
		info->n_to_eat = ft_atoi(av[5]);
	else
		info->n_to_eat = -1;
	ft_mutex(info);
	init_philo_struct(info);
}
