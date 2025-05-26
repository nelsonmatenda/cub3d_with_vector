/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:01:43 by matenda           #+#    #+#             */
/*   Updated: 2025/05/25 08:40:55 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWS_H
# define WINDOWS_H

# define WIDTH 320
# define HEIGHT 200

typedef struct s_img{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_windows
{
	void	*ptr;
	t_img	background;
	t_img	cub3d;
	t_img	map;
}	t_win;


#endif
