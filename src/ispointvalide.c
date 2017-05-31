/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispointvalide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:24:49 by thou              #+#    #+#             */
/*   Updated: 2017/05/31 14:57:20 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "omen.h"

int		isbatiment(t_gps gps)
{
	if (gps.lat > 0)
		return (1);
	return (0);
}

t_gps	transform_to_gps(double x, double y, t_gps gps)
{
	t_gps	point;

	point.lat = gps.lat + 0.0000089831 * y;
	point.lon = gps.lon + 0.0000089831 *  x / cos(gps.lon);
	return (point);
}

int	ispointvalide(int x, int y, t_gps gps)
{
	t_gps	point;
	int		n;

	if (x * x + y * y > 80 * 80 )
		return (0);
	point = transform_to_gps(x, y, gps);
	if ((n = isbatiment(point)) == 0)
		return (0);
	else
		return (n);
}

