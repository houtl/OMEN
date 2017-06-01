/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:58:50 by ibtraore          #+#    #+#             */
/*   Updated: 2017/06/01 07:43:41 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

double		get_angle_horizontal(t_env *e, int x, int y, int num)
{
	double ah;

	int dx;
	int dy;
	double rho;

	dx = e->ant[num]->x - x;
	dy = e->ant[num]->y - y;
	rho = sqrtf(dx * dx + dy * dy ) ;
	ah = (dy >= 0.0) ? acos(dx / (double)sqrtf(dx * dx + dy * dy)) : 2 * M_PI - acos( dx /(double) sqrtf(dx * dx + dy * dy));
	ah *= M_PI/180.0 * ft_abs(ah);
	return (ah);
}


double		get_angle_vertical(t_env *e, int x, int y, double z, int num)
{
	double  av;

	int dx;
	int dy;
	int dz;
	double  d;

	dx = e->ant[num]->x - x;
	dy = e->ant[num]->y - y;
	dz = e->ant[num]->z - z;
	d = sqrt(dx * dx + dy * dy + dz * dz);
	av = asin(e->ant[num]->z / d);
	av = av * M_PI /  180.0 ;
	return (av);
}


double			get_field(int x, int  y, double z, t_env *e, int num)
{
	double field;
	double		 d;
	int dx;
	int dy;
	int dz;
	double  angle_v;
	double  angle_h;
	double rho;

	dx = e->ant[num]->x - x;
	dy = e->ant[num]->y - y;
	dz = e->ant[num]->z - z;
	rho = sqrtf(dx * dx + dy * dy + dz * dz);
	angle_h = get_angle_horizontal(e, x, y, num);
	angle_v = get_angle_vertical(e, x, y, z, num) ;
	e->ant[num]->gamma  = e->horizontal[(int)angle_v%360] + e->vertical[(int)angle_h%360];
	d = sqrt(dx * dx + dy * dy + dz * dz);
	field = (7.0 / d) * sqrtf(e->ant[num]->erp )/ ((double)e->ant[num]->gamma == 0.0 ? 1 : (double)e->ant[num]->gamma); 
	return (field);
}

double		total_field_at_point(int x, int y, double z, t_env *e)
{
	double field;
	int i;
	double  tmp;

	field = 0.0;
	i = -1;

	while (++i < e->total_antenna)
	{
		tmp = get_field(x, y, z, e, i);
		field += tmp;
	}
	return (field);
}
