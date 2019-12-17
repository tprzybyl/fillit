/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 17:07:49 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:31:53 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	char		**array;
	int			i;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	i = ft_scan(&array, av[1]);
	if (i == -1)
	{
		ft_putendl("error");
		return (0);
	}
	ft_tetriminos(array, i);
	return (0);
}
