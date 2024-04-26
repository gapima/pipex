/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:29:47 by glima             #+#    #+#             */
/*   Updated: 2023/11/09 17:34:04 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s, char *t)
{
	if (!s)
		return (2);
	if (t)
	{
		write(2, "-bash: ", 7);
		write(2, t, ft_strlen(t));
		write(2, ": ", 2);
	}
	while (*s)
	{
		write(2, &(*s), 1);
		s++;
	}
	write(2, "\n", 1);
	return (2);
}