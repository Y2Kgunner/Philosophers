/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:04:16 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/14 00:02:12 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *args)
{
	t_phils	*phils;
	t_info	*info;

	phils = (t_phils *)args;
	info = phils->info;
	if (phils->philo_id % 2)
		usleep(15000);
	pthread_mutex_lock(&(info->meals));
	while (!(info->dead))
	{
		pthread_mutex_unlock(&(info->meals));
		// ft_eat(phils, info);
		ft_dine(phils);
		if (info->ate)
			break ;
		print_state(info, phils->philo_id, "is sleeping");
		ft_sleep(info->tts, info);
		print_state(info, phils->philo_id, "is thinking");
		pthread_mutex_lock(&(info->meals));
	}
	pthread_mutex_unlock(&(info->meals));
	return (NULL);
}

static void	ft_death(t_info *info, t_phils *phils)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(info->meals));
	while (i < info->n_philos && !(info->dead))
	{
		pthread_mutex_unlock(&(info->meals));
		pthread_mutex_lock(&(info->meals));
		if (ft_elapsed(phils[i].eat_gap, ft_time()) > info->ttd)
		{
			print_state(info, i, "died");
			info->dead = 1;
		}
		pthread_mutex_unlock(&(info->meals));
		i++;
		usleep(100);
		pthread_mutex_lock(&(info->meals));
	}
	pthread_mutex_unlock(&(info->meals));
}

static void	ft_state(t_info *info, t_phils *phils)
{
	int	i;

	pthread_mutex_lock(&(info->meals));
	while (!(info->ate))
	{
		pthread_mutex_unlock(&(info->meals));
		ft_death(info, phils);
		if (info->dead)
			break ;
		i = 0;
		while (info->n_to_eat != -1 && i < info->n_philos && \
				phils[i].if_ate >= info->n_to_eat)
			i++;
		if (i == info->n_philos)
		{	
			pthread_mutex_lock(&(info->meals));
			info->ate = 1;
			pthread_mutex_unlock(&(info->meals));
		}
		pthread_mutex_lock(&(info->meals));
	}
	pthread_mutex_unlock(&(info->meals));
}

int	ft_threads(t_info *info)
{
	t_phils	*phils;
	int		i;

	phils = info->phils;
	info->init_time = ft_time();
	i = 0;
	while (i < info->n_philos)
	{
		pthread_create(&(phils[i].tid), NULL, thread_routine, &(phils[i]));
		pthread_mutex_lock(&(info->meals));
		phils[i].eat_gap = ft_time();
		pthread_mutex_unlock(&(info->meals));
		i++;
	}
	ft_state(info, phils);
	destroy_mutex(info, phils);
	return (0);
}
