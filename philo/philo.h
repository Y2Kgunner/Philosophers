/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:58:46 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/14 00:02:02 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_phils
{
	pthread_t			tid;
	struct s_info		*info;
	int					philo_id;
	int					if_ate;
	int					l_fork;
	int					r_fork;
	long long			eat_gap;
}				t_phils;

typedef struct s_info
{
	t_phils			phils[200];
	pthread_mutex_t	meals;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	print;
	int				l_state[100];
	int				r_state[100];
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

int				ft_threads(t_info *info);
void			destroy_mutex(t_info *destroy, t_phils *phils);
void			ft_eat(t_phils *phils, t_info *info);
void			ft_dine(t_phils *dine);

#endif	