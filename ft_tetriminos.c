/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tetriminos.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 17:08:57 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 20:55:18 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_makedest(int size)
{
	int		i;
	int		j;
	char	**dest;

	dest = (char**)malloc(sizeof(char*) * (size + 3));
	dest[size + 2] = NULL;
	i = 0;
	while (i < size + 2)
	{
		dest[i] = ft_strnew(size + 2);
		i++;
	}
	i = 0;
	while (i < size + 2)
	{
		j = -1;
		while (++j < size + 2)
			dest[i][j] = (i == 0 || j == 0 || i == size + 1 ||
					j == size + 1) ? '?' : '.';
		i++;
	}
	return (dest);
}

void		ft_remove(char ***dest, int k)
{
	int y;
	int x;

	y = 1;
	while ((*dest)[y][1] != '?')
	{
		x = 1;
		while ((*dest)[y][x] != '?')
		{
			if ((*dest)[y][x] == (k))
			{
				(*dest)[y][x] = '.';
			}
			x++;
		}
		y++;
	}
}

void		ft_display(char **dest)
{
	int y;
	int x;

	y = 1;
	while (dest[y][1] != '?')
	{
		x = 1;
		while (dest[y][x] != '?' && dest[y][x])
		{
			ft_putchar(dest[y][x]);
			x++;
			if (dest[y][x] == '?')
				ft_putchar('\n');
		}
		y++;
	}
}

void		ft_tetriminos(char **array, int i)
{
	t_grid		*args;
	int			size;

	args = malloc(sizeof(t_grid));
	args->array = array;
	size = 2;
	while (i * 4 > size * size)
		size++;
	while (size)
	{
		args->dest = ft_makedest(size);
		if (ft_fillit(args, 1, 1, 0))
		{
			ft_display(args->dest);
			ft_arrstrdel(args->dest);
			ft_arrstrdel(args->array);
			free(args);
			return ;
		}
		ft_arrstrdel(args->dest);
		size++;
	}
}
