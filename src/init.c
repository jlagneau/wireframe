/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/21 19:58:51 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init(char ***coord)
{
	t_env	e;

	e.pers = &get_realcoord_para;
	if (!(e.coord = coord))
		return (EXIT_FAILURE);
	if (!(e.mlx = mlx_init()))
		return (EXIT_FAILURE);
	if (!(e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, PROGRAM_NAME)))
		return (EXIT_FAILURE);
	if (!(e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT)))
		return (EXIT_FAILURE);
	if (!(e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.end))))
		return (EXIT_FAILURE);
	if (!(mlx_key_hook(e.win, event_keyboard_handler, &e)))
		return (EXIT_FAILURE);
	if (!(mlx_mouse_hook(e.win, event_mouse_handler, &e)))
		return (EXIT_FAILURE);
	if (!(mlx_expose_hook(e.win, event_expose_handler, &e)))
		return (EXIT_FAILURE);
	mlx_loop(e.mlx);
	return (EXIT_SUCCESS);
}
