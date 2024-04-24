/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:12:04 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/08 23:41:05 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_dine(t_phils *dine)
{
	t_info	*temp;

	temp = dine->info;
	sem_wait(temp->forks);
	print_state(temp, dine->philo_id, "has taken a fork");
	sem_wait(temp->forks);
	print_state(temp, dine->philo_id, "has taken a fork");
	sem_wait(temp->meals);
	print_state(temp, dine->philo_id, "is eating");
	dine->eat_gap = ft_time();
	sem_post(temp->meals);
	ft_sleep(temp->tte, temp);
	(dine->if_ate)++;
	sem_post(temp->forks);
	sem_post(temp->forks);
}

static void	ft_death(t_info *info, t_phils *phils)
{
	if (ft_elapsed(phils->eat_gap, ft_time()) > info->ttd)
	{
		print_state(info, phils->philo_id, "died");
		info->dead = 1;
		sem_wait(info->print);
		exit (1);
	}
}

static void	*ft_state(void *args)
{
	t_info	*info;
	t_phils	*phils;

	phils = (t_phils *)args;
	info = phils->info;
	while (!(info->ate))
	{
		sem_wait(info->meals);
		ft_death(info, phils);
		sem_post(info->meals);
		if (info->dead)
			break ;
		if (info->n_to_eat != -1 && phils->if_ate >= info->n_to_eat)
			break ;
	}
	return (NULL);
}

static void	sem_routine(void *args)
{
	t_phils	*phils;
	t_info	*info;
	int		count;

	count = 0;
	phils = (t_phils *)args;
	info = phils->info;
	phils->eat_gap = ft_time();
	pthread_create(&(phils->tid), NULL, ft_state, args);
	if (phils->philo_id % 2)
		usleep(15000);
	while (!(info->dead))
	{
		ft_dine(phils);
		if (info->n_to_eat != -1 && phils->if_ate >= info->n_to_eat)
			break ;
		print_state(info, phils->philo_id, "is sleeping");
		ft_sleep(info->tts, info);
		print_state(info, phils->philo_id, "is thinking");
		count++;
	}
	pthread_join(phils->tid, NULL);
	if (info->dead)
		exit (1);
	exit (0);
}

int	ft_sem(t_info *info)
{
	t_phils	*phils;
	int		i;

	phils = info->phils;
	info->init_time = ft_time();
	i = 0;
	while (i < info->n_philos)
	{
		phils[i].pid = fork();
		if (phils[i].pid == 0)
			sem_routine(&(phils[i]));
		i++;
		usleep(100);
	}
	destroy_sem(info);
	return (0);
}
