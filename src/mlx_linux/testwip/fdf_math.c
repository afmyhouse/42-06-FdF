/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/16 18:59:38 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include	"mlx.h"
//#include	"mlx_int.h"
#include	"myfdf.h"

int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
void	ft_abs(double *n)
{
	if (*n < 0)
		*n = *n * (-1);
	return ;
}
double	abs_d(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int max_i(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int min_i(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char sign_d(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}
int	my_round(double n)
{
	if ((sign_d(n) * (n - (int)n)) >= 0.5)
		return ((int)n + sign_d(n));
	return ((int)n);
}
int	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}
