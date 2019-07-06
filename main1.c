/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:59:39 by kngalalu          #+#    #+#             */
/*   Updated: 2019/07/06 14:22:12 by vkosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include "./libft/libft.h"

/*# define BUFF_SIZE 54*/

int		 main()
{
	int 	fd;
	char	*line;
	char 	ret;
	
	fd = open("gen.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);	
	}
	return (0);
}

/*int		main(int argc, char **av)
{
	int		fd,fd1;
	char	*str;
	char	*ret;
	

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(av[1], O_RDONLY);
	else if (argc > 2)
         fd1 = open(av[2], O_RDONLY);
	else
		return (2);
	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	while ((get_next_line(fd, &str)) > 0)
	{
		ft_putendl(str);
		//free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}*/
