/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_randstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:24:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/03/23 01:06:42 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperLibft.h"

static int	_buf_iteration(int fd, char *buf, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		while (!ft_isalpha(buf[i]) && !ft_isdigit(buf[i]) && \
		buf[i] != '_' && buf[i] != '-' && buf[i] != '+')
		{
			if (read(fd, buf + i, 1) != 1)
				return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_randomstr(char *prefix, char *suffix, size_t len)
{
	int			fd;
	char		*buf;
	char		*str;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = ft_calloc(sizeof(char), len + 1);
	if (!buf)
		return (close(fd), NULL);
	if (!_buf_iteration(fd, buf, len))
		return (close(fd), free(buf), NULL);
	close(fd);
	str = ft_strrjoin(prefix, buf, suffix);
	free(buf);
	return (str);
}
