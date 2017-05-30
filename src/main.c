/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:49:49 by thou              #+#    #+#             */
/*   Updated: 2017/05/30 18:23:37 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "omen.h"

int main(int ac, char **av)
{
	t_env		env;
	t_gps		gps;
	int			z;
	double		e;
	t_res		r;

	e->ant = get_antennes(av[1]);//read file Antennes.csv, put in table ant.
	get_attenuation(&env);
	//read file "80010664_0821_x_co_m45_02t.msi", input to 2 tab attenuation: *horizontal *vertical.
	//example: horizontal[0] = 0.00;
	//	       horizontal[1] = 0.01;
	//	       horizontal[2] = 0.02;
	//		   horizontal[35] = 3.26;
	//		   horizontal[359] = 0.00;
	//		   vertical[0] = 0.17;
	//		   vertical[15]= 8.41;
	gps = get_gps(av[1]);
	//read file "Coordinates.csv", obtenu le position gps des antennes.
	x = -81;
	while (++x < 80)
	{
		y = -81;
		while (++y < 80)
		{
			if (bat = ispointvalide(x, y, gps, &z))//point est dans rond? est dans batiment? bat = batiment nu.
			{
				r = get_field(x, y, z, &env);
				//calcul  du champ pour une antenne sur le point.
				res_to_list(&env, r);
				//list->content_size == bat ? 
				//list->content->e < r->e ? (list->content = r)
			}
		}
	}
	list_to_file(&env);
	//output list to .csv file.
}
