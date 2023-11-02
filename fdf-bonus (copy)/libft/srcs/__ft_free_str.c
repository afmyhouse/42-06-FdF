/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/31 18:05:15 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Free allocated memory of a string and inicialize pointer to NULL
/// @param str	Pointer to string
void	ft_free_str(char **str)
{
	char	**tmp;

	tmp = str;
	while (tmp && *tmp)
	{
		ft_free(*tmp);
		tmp++;
	}
	free(str);
	str = NULL;
}

void	ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}