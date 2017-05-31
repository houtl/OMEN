/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:15:54 by ibtraore          #+#    #+#             */
/*   Updated: 2017/05/31 17:10:57 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"


int			search(double lat, double lon, char **tab)
{
	int i;
	double _lat;
	doubleble _lon;
	char	*trim;
	char *split[2];
	double lat2;
	double  lon2;
	double flag1;
	double flag2;
	int conddtinu;
	int id;

	i = 0;
	id = 0;
	continu = 1;
	while (tab[i])
	{
		flag1 = 0;
		flag2 = 0;
		trim = ft_strtrim(tab[i]);
		if ((ft_strcmp(trim , "\"id\""), 4) == 0)
			id = ft_atoi(trim);
		if ((ft_strncmp(trim, "\"lat\"") ,4) == 0) 
		{
			split = ft_strsplit(trim, ' ');
			lat2 = ft_atof(split[1]);
			if (abs((int)lat2 - lat) <= 1)
				flag1 = 1;
		}
		if ((ft_strncmp(trim, "\"lon\"") ,4) == 0) 
		{
			split = ft_strsplit(trim, ' ');
			lat2 = ft_atof(split[1]);
			if (abs((int)lat2 - lon) <= 1)
				flag2 = 1;
		}
		ft_strdel(&trim);
		if (flag1 && flag2)
			return (id);
		i++;
	}
	return (0);
}

int			is_bulding(int id,  t_bulding *list, char **tab, int *bulding_id)
{
		t_bulding *tmp;

		tmp = list;
		while (tmp && id)
		{
			if (0 != id)
			{
				*bulding_id = id;
				return (TRUE);
			}
			tmp = tmp->next;
		}
		return (TFALSE);
}

int			isbatiment(t_gps gps)
{
	char **tab;
	int num;
	int id;
	t_bulding *list;
	int bulding_id;

	tab = get_text("long.txt". int &num);
	id = search(gps.lat, gps.lon, tab);
	bulding_id(tab);
	if (TRUE = = is_bulding(id, list, tab, &bulding_id))
		return (bulding_id);
	return (0);
	
}
