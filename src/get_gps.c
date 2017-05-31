/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:49:51 by thou              #+#    #+#             */
/*   Updated: 2017/05/31 15:09:25 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "omen.h"

t_gps	get_gps(char *str)
{
	int		fd;
	char	*line;
	t_gps	gps;

	if ((fd = open("data/Coordinates.csv", O_RDONLY)) < 0)
		err_exit("coordinates.csv error");
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(str, line, 8) == 0)
		{
			gps.lon = atof(line + 9);
			gps.lat = atof(line + 20);
			free(line);
			close(fd);
			return (gps);
		}
		free(line);
	}
	err_exit("cat not get gps info");
	gps.lon = 0;
	gps.lat = 0;
	return (gps);
}
