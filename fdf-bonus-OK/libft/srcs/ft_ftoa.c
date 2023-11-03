/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:53:41 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/02 21:29:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Converts a float to a string
/// @param f	The float to be converted
/// @return		The string representation of the float
char	*ft_ftoa(float f)
{
	char	*part;
	char	*tmp;
	char	*res;
	int		ipart;
	int		fpart;

	ipart = (int)f;
	fpart = (int)((f - ipart) * 100);
	if (f < 0)
		fpart *= -1;
	part = ft_itoa(ipart);
	if (ipart == 0 && f < 0)
	{
		tmp = ft_strjoin("-", part);
		free(part);
		part = tmp;
	}
	tmp = ft_strjoin(part, ".");
	free(part);
	part = ft_itoa(fpart);
	res = ft_strjoin(tmp, part);
	free(tmp);
	free(part);
	return (res);
}
