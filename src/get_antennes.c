/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:59:06 by ibtraore          #+#    #+#             */
/*   Updated: 2017/05/31 10:31:48 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"


t_ant		load_antenna_data(char *line)
{
	char	**tab;
	int		i;
	int total;
	t_ant	antenna;

	i = -1;
	total = -1;
	tab = ft_strsplit(line, ';');
	while (tab[++total])
		;
	antenna.operators = ft_strdup(tab[0]);
	antenna.sector_number = ft_atoi(tab[1]);
	antenna.sector_name = ft_strdup(tab[2]);
	antenna.antenna = ft_strdup(tab[3]);

	antenna.azimut = ft_atoi(tab[4]);
	antenna.frequency = ft_atoi(tab[5]);
	antenna.erp = ft_atoi(tab[6]);
	antenna.x = ft_atoi(tab[7]);
	antenna.y = ft_atoi(tab[8]);
	antenna.z = ft_atoi(tab[9]);

	antenna.mecatilit = ft_atoi(tab[10]);
	antenna.electilit = ft_atoi(tab[11]);
	antenna.perimeter = ft_atoi(tab[12]);
	
	while (++i < total)
		ft_strdel(&tab[i]);
	return (antenna);
}

void	get_antenna(char *file,  t_env *e)
{
	char	*line;
	int		fd;
	char	*tab;
	int		i;

	e->total_antenna = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		err_exit("wrong file");
	get_next_line(fd, &line);
	if (line)
		ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		e->ant[++e->total_antenna] = load_antenna_data(line);
		ft_strdel(&line);
	}
	close(fd);
}
