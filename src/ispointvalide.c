/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispointvalide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:24:49 by thou              #+#    #+#             */
/*   Updated: 2017/06/01 04:53:45 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

/*int		isbatiment(t_gps gps)
{
	t_bulding	*list;

	list = get_list();
	while (list)
	{
		if (list->lat - gps.lat < 0.000009 && list->lon - gps.lon < 0.000009 / cos(gps.lon))
			return (list->id);
		list = list->next;
	}
	return (0);
}*/

t_gps	transform_to_gps(double x, double y, t_gps gps)
{
	t_gps	point;

	point.lat = gps.lat + 0.0000089831 * y;
	point.lon = gps.lon + 0.0000089831 *  (double)x / cos(gps.lon);
	return (point);
}

int	ispointvalide(int x, int y, t_gps gps, t_env *e)
{
	t_gps	point;
	int		bat_num;

	if (x * x + y * y > 80 * 80 )
		return (0);
	point = transform_to_gps(x, y, gps);
	bat_num = isbatiment(point,e);
	//printf("isbati = %d\n", bat_num);
	if (bat_num  == 0)
		return (0);
	else
		return (bat_num);
}

