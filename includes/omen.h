/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omen.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:26:54 by thou              #+#    #+#             */
/*   Updated: 2017/05/31 14:57:51 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OMEN_H
# define OMEN_H

# include <math.h>
# include <stdio.h>
# include "libft.h"
# define MAX_ANTENNA 1000

# define Z 12
# define MAX_ANTENNA 1000

typedef struct		s_antenna
{
	char			*operators;
	int				sector_number;
	char			*sector_name;
	char			*antenna;
	double			azimut;
	double			frequency;
	double			erp;
	double			x;
	double			y;
	double			z;
	double			mecatilit;
	double			electilit;
	double			perimeter;
	double			gamma;
}					t_ant;

typedef struct		s_gps
{
	double			lat;
	double			lon;
}					t_gps;

typedef struct		s_env
{
	char			*name;
	t_ant			ant[MAX_ANTENNA];
	double			*horizontal;
	double			*vertical;
	t_list			*list;
	double			gamma;
	int				total_antenna;
}					t_env;

typedef struct		s_result
{
	int				x;
	int				y;
	double			z;
	double			e;
	int				bat;
}					t_res;

void				print_all_antenna(t_env *e);
void				get_antennes(char *file, t_env *e);
void				err_exit(char *str);
void				get_attenuation(t_env *e);
t_gps				get_gps(char *str);
int					ispointvalide(int x, int y, t_gps gps);
double				total_field_at_point(int x, int y, double z, t_env *e);

#endif
