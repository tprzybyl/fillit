/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_analyse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 15:34:53 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 15:39:12 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_analysebisbis(const char *elem)
{
	if (ft_strstr(elem, "###.\n#...\n") || ft_strstr(elem, ".###\n.#..\n"))
		return (ft_strdup("00011020"));
	if (ft_strstr(elem, "..#.\n###.\n") || ft_strstr(elem, "...#\n.###\n"))
		return (ft_strdup("0001-11-21"));
	if (ft_strstr(elem, "##..\n.#..\n.#..\n") ||
			ft_strstr(elem, ".##.\n..#.\n..#.\n") ||
			ft_strstr(elem, "..##\n...#\n...#\n"))
		return (ft_strdup("00101112"));
	if (ft_strstr(elem, "#...\n#...\n##..\n") ||
			ft_strstr(elem, ".#..\n.#..\n.##.\n") ||
			ft_strstr(elem, "..#.\n..#.\n..##\n"))
		return (ft_strdup("00010212"));
	return (0);
}

static char	*ft_analysebis(const char *elem)
{
	if (ft_strstr(elem, "##..\n.##.\n") || ft_strstr(elem, ".##.\n..##\n"))
		return (ft_strdup("00101121"));
	if (ft_strstr(elem, ".##.\n##..\n") || ft_strstr(elem, "..##\n.##.\n"))
		return (ft_strdup("001001-11"));
	if (ft_strstr(elem, "#...\n##..\n.#..\n") ||
			ft_strstr(elem, ".#..\n.##.\n..#.\n") ||
			ft_strstr(elem, "..#.\n..##\n...#\n"))
		return (ft_strdup("00011112"));
	if (ft_strstr(elem, "...#\n..##\n..#.\n") ||
			ft_strstr(elem, "..#.\n.##.\n.#..\n") ||
			ft_strstr(elem, ".#..\n##..\n#...\n"))
		return (ft_strdup("0001-11-12"));
	if (ft_strstr(elem, "###.\n..#.\n") || ft_strstr(elem, ".###\n...#\n"))
		return (ft_strdup("00102021"));
	if (ft_strstr(elem, "#...\n###.\n") || ft_strstr(elem, ".#..\n.###\n"))
		return (ft_strdup("00011121"));
	if (ft_strstr(elem, "##..\n#...\n#...\n") ||
			ft_strstr(elem, ".##.\n.#..\n.#..\n") ||
			ft_strstr(elem, "..##\n..#.\n..#.\n"))
		return (ft_strdup("00100102"));
	if (ft_strstr(elem, "...#\n...#\n..##\n") ||
			ft_strstr(elem, "..#.\n..#.\n.##.\n") ||
			ft_strstr(elem, ".#..\n.#..\n##..\n"))
		return (ft_strdup("000102-12"));
	return (ft_analysebisbis(elem));
}

char		*ft_analyse(const char *elem)
{
	if (ft_strstr(elem, "##..\n##..\n") || ft_strstr(elem, ".##.\n.##.\n") ||
			ft_strstr(elem, "..##\n..##\n"))
		return (ft_strdup("00011011"));
	if (ft_strstr(elem, "####\n"))
		return (ft_strdup("00102030"));
	if (ft_strstr(elem, "#...\n#...\n#...\n#...\n") ||
			ft_strstr(elem, ".#..\n.#..\n.#..\n.#..\n") ||
			ft_strstr(elem, "...#\n...#\n...#\n...#\n") ||
			ft_strstr(elem, "..#.\n..#.\n..#.\n..#.\n"))
		return (ft_strdup("00010203"));
	if (ft_strstr(elem, ".#..\n###.\n") || ft_strstr(elem, "..#.\n.###\n"))
		return (ft_strdup("000111-11"));
	if (ft_strstr(elem, "###.\n.#..\n") || ft_strstr(elem, ".###\n..#.\n"))
		return (ft_strdup("00101120"));
	if (ft_strstr(elem, "#...\n##..\n#...\n") ||
			ft_strstr(elem, ".#..\n.##.\n.#..\n") ||
			ft_strstr(elem, "..#.\n..##\n..#.\n"))
		return (ft_strdup("00011102"));
	if (ft_strstr(elem, "..#.\n.##.\n..#.\n") ||
			ft_strstr(elem, "...#\n..##\n...#\n") ||
			ft_strstr(elem, ".#..\n##..\n.#..\n"))
		return (ft_strdup("0001-1102"));
	return (ft_analysebis(elem));
}
