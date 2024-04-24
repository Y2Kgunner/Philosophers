/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:45:24 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/14 00:02:27 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dine(t_phils *dine)
{
	t_info	*temp;

	temp = dine->info;
	pthread_mutex_lock(&(temp->forks[dine->l_fork]));
	// temp->l_state[dine->l_fork] = 1;
	print_state(temp, dine->philo_id, "has taken a fork");
	pthread_mutex_lock(&(temp->forks[dine->r_fork]));
	// temp->r_state[dine->r_fork] = 1;
	print_state(temp, dine->philo_id, "has taken a fork");
	pthread_mutex_lock(&(temp->meals));
	print_state(temp, dine->philo_id, "is eating");
	dine->eat_gap = ft_time();
	pthread_mutex_unlock(&(temp->meals));
	ft_sleep(temp->tte, temp);
	(dine->if_ate)++;
	pthread_mutex_unlock(&(temp->forks[dine->l_fork]));
	pthread_mutex_unlock(&(temp->forks[dine->r_fork]));
}

// void	ft_eat(t_phils *phils, t_info *info)
// {
// 	// if (info->l_state[phils->l_fork] == 0 && info->r_state[phils->r_fork] == 0)
// 	// {
// 		ft_dine(phils);
// 		// info->l_state[phils->l_fork] = 0;
// 		// info->r_state[phils->r_fork] = 0;
// 	// }
// }
