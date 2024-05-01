/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:50:52 by glima             #+#    #+#             */
/*   Updated: 2024/04/26 18:50:54 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **ag, char **envp)
{
	int	f1;
	int	f2;

	if (ac != 5)
		return (ft_putstr("Invalid number of arguments.", 0));
	if (check_empty(ag[2]) || check_empty(ag[3]))
		return (1);
	f1 = open(ag[1], O_RDONLY);
	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (f1 < 0)
		return (ft_putstr(strerror(errno), ag[1]));
	if (f2 < 0)
		return (ft_putstr(strerror(errno), ag[4]));
	pipex(f1, f2, ag, envp);
	if (close(f1) < 0 || close(f2) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}
