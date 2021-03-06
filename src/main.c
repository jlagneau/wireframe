/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 17:40:43 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	int			ret;
	char		***coord;

	coord = NULL;
	if (argc == 1 || argc > 3)
		print_usage();
	else if (argc == 2)
		coord = arg_getcoord(argv[1]);
	else if (argc == 3)
	{
		coord = arg_getcoord(argv[2]);
		if (ft_strcmp(argv[1], "-d") == 0)
			print_debug(coord);
		else
			print_usage();
	}
	ret = init(coord);
	return (ret);
}
