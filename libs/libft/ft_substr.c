/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:09 by glima             #+#    #+#             */
/*   Updated: 2023/10/31 11:02:19 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*r;
	size_t			i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = (unsigned int)ft_strlen(s);
	if (s_len < start)
		len = 0;
	else if (s_len < start + len)
		len = s_len - start;
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	while (i < len)
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}
