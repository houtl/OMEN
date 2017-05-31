/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:58:50 by ibtraore          #+#    #+#             */
/*   Updated: 2017/05/31 15:00:27 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

double		get_angle_horizontal(t_env *e, int x, int y, int num)
{
	double ah;

	int dx;
	int dy;

	dx = e->ant[num].x - x;
	dy = e->ant[num].y - y;
	ah = atan2(dy, dx);
	return (ah);
}


double		get_angle_vertical(t_env *e, int x, int y, double z, int num)
{
	double  av;

	int dx;
	int dy;
	int dz;
	int d;

	dx = e->ant[num].x - x;
	dy = e->ant[num].y - y;
	dz = e->ant[num].z - z;
	d = sqrt(dx * dx + dy * dy + dz * dz);
	av = asin(e->ant[num].z / d);
	return (av);
}


double			get_field(int x, int  y, double z, t_env *e, int num)
{
	double field;
	int		 d;
	int dx;
	int dy;
	int dz;
	int angle_v;
	int  angle_h;


	dx = e->ant[num].x - x;
	dy = e->ant[num].y - y;
	dz = e->ant[num].z - z;
	angle_h = get_angle_horizontal(e, x, y, num);
	angle_v = get_angle_vertical(e, x, y, z, num);
	e->ant[num].gamma  = e->horizontal[angle_v] + e->vertical[angle_h];
	d = sqrt(dx * dx + dy * dy + dz * dz);
	field = (7.0 / d) * sqrt(e->ant[num].erp / e->ant[num].gamma); 
	return (field);
}

double		total_field_at_point(int x, int y, double z, t_env *e)
{
	double field;
	int i;

	field = 0.0;
	i = -1;
	while (++i < e->total_antenna)
		field += get_field(x, y, z, e, i);
	return (field);
}
