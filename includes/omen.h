/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omen.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:26:54 by thou              #+#    #+#             */
/*   Updated: 2017/05/30 17:24:16 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OMEN_H
# define OMEN_H

# include "libft.h"

typedef struct		s_antenna
{
	int				azimuth;
	int				erp;
	int				x;
	int				y;
	double			z;
	int				r;
}					t_ant;

typedef struct		s_gps
{
	double			lat;
	double			lon;
}					t_gps;

typedef struct		s_env
{
	t_ant			*ant;
	double			*horizontal;
	double			*vertical;
}					t_env;

#endif
