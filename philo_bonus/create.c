/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:50:32 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/08 22:25:47 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philo_struct(t_info *info)
{
	int	pos;

	pos = 0;
	while (pos < info->n_philos)
	{
		info->phils[pos].philo_id = pos;
		info->phils[pos].if_ate = 0;
		info->phils[pos].eat_gap = 0;
		info->phils[pos].info = info;
		pos++;
	}
}

static void	ft_semaphores(t_info *info)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/meals");
	info->forks = sem_open("/forks", O_CREAT, 0644, info->n_philos);
	info->print = sem_open("/print", O_CREAT, 0644, 1);
	info->meals = sem_open("/meals", O_CREAT, 0644, 1);
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
	ft_semaphores(info);
	init_philo_struct(info);
}
