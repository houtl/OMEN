/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:49:49 by thou              #+#    #+#             */
/*   Updated: 2017/06/01 06:17:16 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

void		err_exit(char *str)
{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(".\n", 2);
		exit(1);
}

void		res_to_list(t_env *e, t_res *r)
{
	t_list	*list;
	t_list	*tmp;

	if (!(e->list))
	{
		e->list = ft_lstnew(r, r->bat);
		return;
	}
	list = e->list;
	while (list)
	{
		if (list->content_size == (size_t)r->bat)
		{
			((t_res*)list->content)->e = (((t_res*)list->content)->e < r->e ? r->e : ((t_res*)list->content)->e);
			return ;
		}
		tmp = list;
		list = list->next;
	}
	tmp->next = ft_lstnew(r, r->bat);
}

void		list_to_file(t_env *e)
{
	int		fd;
	char	*str;
	t_list	*list;
	int		i;
	char	*name;

	name = ft_strjoinfree(ft_strdup(e->name), "_Omens.csv");
	list = e->list;
	fd = (int)fopen(name, "a");
	ft_putstr_fd("OMENID;X;Y;Z;Efield;Approved\n", fd);
	i = 1;
	while (list)
	{
		str = ft_strjoinfree(ft_itoa(i), ";");
		str = ft_strjoinfree2(str, ft_itoa(((t_res*)list->content)->x));
		str = ft_strjoinfree(str, ";");
		str = ft_strjoinfree2(str, ft_itoa(((t_res*)list->content)->y));
		str = ft_strjoinfree(str, ";");
		str = ft_strjoinfree2(str, ft_itoa(((t_res*)list->content)->z));
		str = ft_strjoinfree(str, ";");
		str = ft_strjoinfree(str, ft_itoa(((t_res*)list->content)->e));
		str = ft_strjoinfree(str, ";");
		if (((t_res*)list->content)->e >= 5)
			str = ft_strjoinfree(str, "NO");
		else
			str = ft_strjoinfree(str, "YES");
		ft_putstr_fd(str, fd);
		if (str)
			free(str);
		list = list->next;
	}
	close(fd);
}

int main(int ac, char **av)
{
	t_env		env;
	t_gps		gps;
	int			z;
	t_res		r;
	int			x;
	int			y;

	if (ac ==  2)
	{
		z = Z;
		env.name = av[1];
		env.name = av[1];
		get_antennes(av[1], &env);
		get_attenuation(&env);
		gps = get_gps(env.name);
		x = -81;
		while (++x < 80)
		{
			y = -81;
			while (++y < 80)
			{
				if (r.bat == ispointvalide(x, y, gps, &env))
				{
					r.x = x;
					r.y = y;
					r.z = 10;
					r.e = total_field_at_point(x, y, z, &env);;
					res_to_list(&env, &r); 
				}
			}
		}
		list_to_file(&env);
	}
	ft_putstr("Merci de verifier le resultat dans le fichier creer");
	return (0);
}
