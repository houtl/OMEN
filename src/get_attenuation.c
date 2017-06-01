/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attenuation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:23:24 by thou              #+#    #+#             */
/*   Updated: 2017/06/01 06:04:37 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

void	get_attenuation(t_env *e)
{
	int		fd;
	char	*line;
	char	*str;
	int		nl;

	if ((fd = open("data/antenna/80010664_0821_x_co_m45_02t.msi", O_RDONLY)) < 0)
		err_exit("msi file error");
	nl = 0;
	e->horizontal = (double*)malloc(sizeof(double) * 360);
	e->vertical = (double*)malloc(sizeof(double) * 360);
	while (get_next_line(fd, &line) > 0)
	{
		++nl;
		str = line;
		if (nl > 6 && nl < 367)
		{
			while (*str != ' ')
				++str;
			e->horizontal[nl - 7 <  0 ? 0 : nl - 7] = atof(str);
		}
		if (nl > 367)
		{
			while (*str != ' ')
				++str;
			e->vertical[nl - 368 < 0 ? 0 :  nl - 360] = atof(str);
		}
		if (line)
			free(line);
	}
	close(fd);
}

