/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:14:15 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/06 15:39:22 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfutils.h"

void	*ft_callocb(size_t nmemb, size_t size)
{
	size_t			max;
	unsigned char	*ptr;
	int				nb;
	int				i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	max = nmemb * size;
	if (max > INT32_MAX)
		return (NULL);
	nb = nmemb * size;
	ptr = (unsigned char *) malloc(nb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nb)
		ptr[i++] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_atoui(const char *s)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = 0;
	if (s[i] == 0)
		return (n);
	while (s[i] >= '0' && s[i] <= '9')
		n = n * 10 + (s[i++] - '0');
	return (n);
}

void	ft_printfnc(const char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}
