/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:33:52 by glarivie          #+#    #+#             */
/*   Updated: 2016/03/27 23:26:44 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*cur;
	struct stat		stat;
	struct passwd	*passwd;
	struct group	*group;
	int				ret;
	blkcnt_t		total;


	char buf[1024];
	char *rwx;
	ssize_t len;
	char	*tmp;


	total = 0;
	if (argc)
	{
		if ((dir = opendir(argv[1])) == NULL)
		{
			perror("");
			exit(1);
		}
		argv[1] = ft_strjoin(argv[1], "/");
		while ((cur = readdir(dir)))
		{
			ret = lstat((tmp = ft_strjoin(argv[1], cur->d_name)), &stat);
			rwx = get_rwx(stat.st_mode);
			ft_putstr(rwx);
			ft_putstr("  ");
			ft_putnbr(stat.st_nlink);
			ft_putchar(' ');
			passwd = getpwuid(stat.st_uid);
			group = getgrgid(stat.st_gid);
			ft_putstr(passwd->pw_name);
			ft_putstr("  ");
			ft_putstr(group->gr_name);
			ft_putchar(' ');
			size_right(stat.st_size);
			ft_putchar(' ');
			ft_putstr(format_mtime(ctime(&(stat.st_mtime))));
			ft_putchar(' ');
			ft_putstr(cur->d_name);
			if (rwx[0] == 'l')
			{
				if ((len = readlink(cur->d_name, buf, sizeof(buf)-1)) != -1)
			    	buf[len] = '\0';
				ft_putstr(" -> ");
				ft_putendl(buf);
			} else {
				ft_putchar('\n');
			}
			total += stat.st_blocks;

		}
		free(rwx);
		ft_putstr("total ");
		ft_putnbr_endl(total);
		if (closedir(dir) == -1)
		{
			perror("");
			exit(-1);
		}
	}
	return (0);
}
