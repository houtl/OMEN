/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:49:49 by thou              #+#    #+#             */
/*   Updated: 2017/05/30 17:25:15 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "omen.h"

int main(int ac, char **av)
{
	t_ant		*ant;
	int			*horizontal;
	int			*vertical;
	t_gps		gps;
	int			z;

	*ant = get_antennes(av[1]);
	get_attenuation(&horizo, &vertical);
	gps = get_gps(av[1]);
	x = -81;
	while (++x < 80)
	{
		y = -81;
		while (++y < 80)
		{
			if (bat = ispointvalide(x, y, gps, &z))
				get_field(x, y, z, env);
		}
	}
}
