/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_between_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:51:10 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 22:20:12 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Angle between two vector
 *
 * @param a Vector with x and y
 * @param b Vector with x and y
 * @return Angle in rad
 */
float	angle_between_vector(t_vector a, t_vector b)
{
	float	ma;
	float	mb;

	ma = magnitude_of_vector(a);
	mb = magnitude_of_vector(b);
	return (acos( dot_vector(a, b) / (ma * mb)));
}
