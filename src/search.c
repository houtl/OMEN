/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:15:54 by ibtraore          #+#    #+#             */
/*   Updated: 2017/06/01 02:37:50 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

int			search(double lat, double lon, char **tab)
{
	int i;
	char	*trim;
	char **split;
	double lat2;
	double  lon2;
	double flag1;
	double flag2;
	int id;

	i = 0;
	id = 0;
	while (tab[i])
	{
		flag1 = 0;
		flag2 = 0;
		trim = ft_strtrim(tab[i]);
		if ((ft_strcmp(trim , "\"id\""), 4) == 0)
			id = ft_atoi(trim);
		if ((ft_strcmp(trim, "\"lat\""), 4) == 0) 
		{
			split = ft_strsplit(trim, ' ');
			lat2 = ft_atof(split[1], 0);
			if (ft_abs((int)lat2 - lat) <= 1)
				flag1 = 1;
		}
		if ((ft_strcmp(trim, "\"lon\"") ,4) == 0) 
		{
			split = ft_strsplit(trim, ' ');
			lon2 = ft_atof(split[1], 0);
			if (((int)lat2 - lon) <= 1 || (int)lat2 - lon >= -1)
				flag2 = 1;
		}
		ft_strdel(&trim);
		if (flag1 && flag2)
			return (id);
		i++;
	}
	return (0);
}

int			is_buulding(int id,  t_bulding *list, int *bulding_id)
{
		t_bulding *tmp;

		tmp = list;
		while (tmp && id)
		{
			if (0 != id)
			{
				*bulding_id = id;
				return (1);
			}
			tmp = tmp->next;
		}
		return (0);
}

int			isbatiment(t_gps gps, t_env *e)
{
	char **tab;
	int num;
	int id;
	t_bulding *list;
	int bulding_id;
	int i;
	char *name[4] = {"GE_0002A6.1443288446.21074101.json",
						"GE_0002A6.1443288446.21074101.json",
						"TG_3150D9.0638297247.54028145.json",
						"TG_3150D9.0638297247.54028145.json"};
	i = -1;
	while (++i < 4)
	{
		if(0 ==  ft_strcmp(name[i], e->name))
		{
			tab = get_text("name[i]" , &num);
			id = search(gps.lat, gps.lon, tab);
			list = get_bulding_id(tab);
			if (1 == is_buulding(id, list, &bulding_id))
				return (bulding_id);
		}
	}
	return (0);
}
