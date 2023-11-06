/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:12:22 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 18:13:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:53:41 by antoda-s          #+#    #+#             */
/*   Updated: 2023/11/03 18:11:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_decitoa(float n, int p)
{
	char		*res;
	int	ln;

	res = (char *)malloc((p + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[p + 1] = '\0';
	p = 0;
	while (res[p])
	{
		n *= 10;
		ln = (int)n;
		n = n - ln;
		res[p] = ln % 10 + 48;
	}
	return (res);
}

/// @brief 		Converts a float to a string
/// @param f	The float to be converted
/// @return		The string representation of the float
char	*ft_ftoa(float f, int p)
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
	part = ft_decitoa(fpart, p);
	res = ft_strjoin(tmp, part);
	free(tmp);
	free(part);
	return (res);
}

int	main(void)
{
	float	f;
	char	*str;

	f = 0.123456;
	str = ft_ftoa(f, 6);
	printf("%s\n", str);
	free(str);
	return (0);
}