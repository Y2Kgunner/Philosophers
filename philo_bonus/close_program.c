/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:02:08 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/08 23:44:51 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	destroy_sem(t_info *destroy)
{
	int	i;
	int	pid;

	i = 0;
	while (i < destroy->n_philos)
	{
		waitpid(-1, &pid, 0);
		if (pid != 0)
		{
			i = 0;
			while (i < destroy->n_philos)
			{	
				kill(destroy->phils[i].pid, SIGTERM);
				i++;
			}
			break ;
		}
		i++;
	}
	sem_close(destroy->forks);
	sem_close(destroy->meals);
	sem_close(destroy->print);
	sem_unlink("/forks");
	sem_unlink("/meals");
	sem_unlink("/print");
}
