/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:29:09 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/14 00:06:41 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_elapsed(long long prev, long long current)
{
	return (current - prev);
}

void	ft_sleep(long long time, t_info *info)
{
	long long	t;

	t = ft_time();
	pthread_mutex_lock(&(info->meals));
	while (!(info->dead))
	{
		pthread_mutex_unlock(&(info->meals));
		if (ft_elapsed(t, ft_time()) >= time)
			break ;
		usleep (1000);
		pthread_mutex_lock(&(info->meals));
	}
	pthread_mutex_unlock(&(info->meals));
}
