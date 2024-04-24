/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:11:39 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/08 23:14:31 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	while (!(info->dead))
	{
		if (ft_elapsed(t, ft_time()) >= time)
			break ;
		usleep (50);
	}
}
