/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 14:01:58 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 19:16:00 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 25

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_grid
{
	char		**dest;
	char		**array;
}				t_grid;

char			*ft_analyse(const char *elem);
int				ft_scan(char ***array, char *path);
void			ft_tetriminos(char **array, int i);
int				ft_fillit(t_grid *args, int x, int y, int k);
void			ft_display(char **dest);
void			ft_remove(char ***dest, int m);
#endif
