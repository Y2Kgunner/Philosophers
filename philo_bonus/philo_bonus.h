/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:22:28 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/08 23:40:32 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_phils
{
	pthread_t			tid;
	pid_t				pid;
	struct s_info		*info;
	int					philo_id;
	int					if_ate;
	long long			eat_gap;
}				t_phils;

typedef struct s_info
{
	t_phils			phils[200];
	sem_t			*meals;
	sem_t			*forks;
	sem_t			*print;
	int				n_philos;
	int				ttd;
	int				tte;
	int				tts;
	int				n_to_eat;
	int				dead;
	int				ate;
	long long		init_time;
}	t_info;

//----------------------------------PARSER------------------------------------//

int				check_args(char **av);

//--------------------------------INIT------------------------------------//

void			init_threads(t_info *data);
void			init_main(t_info *info, char **av);

//--------------------------------UTILS-------------------------------------//

int				ft_atoi(const char *str);

//--------------------------------TIME--------------------------------------//

long long		ft_time(void);
long long		ft_elapsed(long long prev, long long current);
void			ft_sleep(long long time, t_info *info);

//--------------------------------PRINT-------------------------------------//

int				ft_single(char **av);
void			print_state(t_info *info, int i, char *str);

//--------------------------------THREADS-----------------------------------//

int				ft_sem(t_info *info);
void			destroy_sem(t_info *destroy);

#endif	