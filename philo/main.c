/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:14:47 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/12/06 03:31:29 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac != 6)
	{
		printf("INSUFFICIENT ARGUMENTS");
		return (1);
	}
	else if (check_args(av))
		return (1);
	if (ft_single(av))
		return (0);
	init_main(&info, av);
	ft_threads(&info);
	return (0);
}
