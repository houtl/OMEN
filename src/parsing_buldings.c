/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_buldings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:38:53 by ibtraore          #+#    #+#             */
/*   Updated: 2017/05/31 15:14:50 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/omen.h"

int			tab_num(char *file)
{
	int i;
	int fd;
	char *line;
	
	i = 0;
	if ((fd =  open(file , O_RDONLY)) == -1)
		err_exit("Unable to open file");
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		ft_strdel(&line);
	}
	close(fd);
	return (i);
}
char		**get_text(char *file, int *number)
{
	char *line;
	char **tab;
	int fd;
	int i;
	int num;

	num = tab_num(file);
	if (!(tab = (char**)malloc((num + 1) * sizeof(char*))))
		err_exit("unable to allocate");
	if ((fd =  open(file , O_RDONLY)) == -1)
		err_exit("Unable to open file");
	i = 0;
	while (get_next_line(fd, &line) > 0)
		tab[i++] = line;
	*number = i;
	tab[i] = NULL;
	close(fd);
	return (tab);
}

t_bulding			*bulding_id(char **tab)
{
	int i;
	t_bulding *new;
	t_bulding *list;
	t_bulding *tmp;
	char *str;
	char **split;

	char *trim;


	list = NULL;
	i = 0;
	while (tab[i])
	{
		str = ft_strtrim(tab[i]);
		if (ft_strcmp(str, "\"building\": \"yes\"") == 0)
		{
			if (!(new = (t_bulding*)malloc(sizeof(t_bulding))))
				err_exit("no memory");
			trim = ft_strtrim(tab[i + 5]);
			split = ft_strsplit(trim, ' ');
			new->id = ft_atoi(split[1]);
			if (!list)
				list = new;
			else
			{
				tmp = list;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = new;
			}
		}
		i++;
	}
	return (list);
}
