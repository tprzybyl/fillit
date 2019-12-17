/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scan.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 13:43:20 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 20:52:32 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_strgetfrom(const int fd, char **str)
{
	char	tmp[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, tmp, BUFF_SIZE)))
	{
		if (ret < 0)
			return (0);
		tmp[ret] = '\0';
		*str = ft_strfjoin(*str, tmp);
	}
	return (1);
}

static int	ft_checkerrors(const char *str, char ***array)
{
	int										i;
	int										y;

	i = ((ft_strlen(str) + 1) / 21);
	if ((ft_strlen(str) + 1) % 21 || (ft_strcchr(str, '\n') + 1) / 5 != i ||
			ft_strcchr(str, '#') / 4 != i || ft_strcchr(str, '.') / 12 != i ||
			ft_strlen(str) > 546)
	{
		return (0);
	}
	y = 1;
	while (y < i)
	{
		if (str[(y * 21) - 1] != '\n')
			return (0);
		y++;
	}
	*array = (char**)malloc(sizeof(char*) * (i + 1));
	return (i);
}

int			ft_scan(char ***array, char *path)
{
	char	*str;
	int		i;
	int		fd;
	int		j;
	char	*tmp;

	fd = open(path, O_RDONLY);
	str = ft_strnew(0);
	if (!(ft_strgetfrom(fd, &str)) || !(i = ft_checkerrors(str, array)))
		return (-1);
	j = -1;
	while (++j < i)
	{
		if (!(tmp = ft_strsub(str, j * 21, 20)))
			return (-1);
		if (!((*array)[j] = ft_analyse(tmp)))
		{
			ft_strdel(&tmp);
			return (-1);
		}
		ft_strdel(&tmp);
	}
	(*array)[j] = NULL;
	return (i);
}
