/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkosi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:20:30 by vkosi             #+#    #+#             */
/*   Updated: 2019/07/06 11:59:38 by vkosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new(char **s, char **line, int fd, int ret)
{
	char		*tmp;
	int			len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][0] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		if (ret == BUFF_SIZE)
			return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *s[250];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (new(s, line, fd, ret));
}
