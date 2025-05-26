/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_of_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:01:39 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 02:42:10 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Calculate the magnitude of a vector.
 *
 * @param a A vector with x and y
 * @return Magnitude of the vector
 */
float	magnitude_of_vector(t_vector a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2)));
}
