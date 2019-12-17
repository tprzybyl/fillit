/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_backtracking.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:03:41 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:54:56 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_getpoint(int *x, int *y, char **dest)
{
	while (dest[*y][1] != '?')
	{
		while (dest[*y][*x])
		{
			*x += 1;
			if (dest[*y][*x] == '.')
				return (0);
		}
		*y += 1;
		*x = 0;
	}
	return (1);
}

static int	ft_checkit(char **dest, int c)
{
	int y;
	int x;

	y = 1;
	while (dest[y][1] != '?')
	{
		x = 1;
		while (dest[y][x] != '?' && dest[y][x])
		{
			if (dest[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	ft_replace(t_grid *args, int k, int x, int y)
{
	int i;
	int tx;
	int ty;

	i = 0;
	while (args->array[k][i])
	{
		if (args->array[k][i] == '-')
		{
			tx = -1 * (args->array[k][i + 1] - '0');
			i++;
		}
		else
			tx = args->array[k][i] - '0';
		ty = args->array[k][i + 1] - '0';
		args->dest[y + ty][x + tx] = ('A' + k);
		i += 2;
	}
}

static int	ft_cban(t_grid *args, int k, int x, int y)
{
	int i;
	int tx;
	int ty;

	i = 0;
	while (args->array[k][i])
	{
		if (args->array[k][i] == '-')
		{
			tx = -1 * (args->array[k][i + 1] - '0');
			i++;
		}
		else
			tx = args->array[k][i] - '0';
		ty = args->array[k][i + 1] - '0';
		if (args->dest[y + ty][x + tx] != '.')
			return (3);
		i += 2;
	}
	ft_replace(args, k, x, y);
	return (1);
}

int			ft_fillit(t_grid *args, int x, int y, int k)
{
	if (!args->array[k])
		return (1);
	if (ft_checkit(args->dest, k + 'A'))
	{
		if (ft_fillit(args, 1, 1, k + 1) == 1)
			return (1);
	}
	while (args->array[k])
	{
		if (ft_cban(args, k, x, y) == 1)
		{
			if (ft_fillit(args, 1, 1, k + 1) == 1)
				return (1);
		}
		if (ft_getpoint(&x, &y, args->dest))
		{
			break ;
		}
	}
	ft_remove(&args->dest, (k - 1 + 'A'));
	return (0);
}
