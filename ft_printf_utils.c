/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:03:23 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/08 19:29:15 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfutils.h"

int	ft_printfc(const char *sf, const char c)
{
	int	len;
	int	size;

	size = 1;
	len = 1;
	if (sf[0] >= '1' && sf[0] <= '9')
		len += ft_printfwidth(sf[0], ft_atoui(&sf[0]), &size);
	else if (sf[0] != '-')
		len += ft_printfwidth(sf[0], ft_atoui(&sf[1]), &size);
	write(1, &c, 1);
	if (sf[0] == '-')
		len += ft_printfwidthafter(sf[0], ft_atoui(&sf[1]), size);
	return (len);
}

int	ft_printfs(const char *sf, const char *s)
{
	if (!s)
		return (ft_printformat('s', sf, "(null)"));
	return (ft_printformat('s', sf, s));
}

int	ft_printfp(const char *sf, void *ptr)
{
	char	*s;
	int		i;

	if (!ptr)
		return (ft_printformat('o', sf, "(nil)"));
	s = ft_itoabase((size_t) ptr, "0123456789abcdef");
	s = ft_strjoin("0x", s);
	i = ft_printformat('p', sf, s);
	free(s);
	return (i);
}

int	ft_printfdi(const char *sf, int n)
{
	char			*s;
	int				i;
	unsigned int	nb;
	int				sign;
	int				offset;

	offset = 0;
	sign = 1;
	if (n < 0)
	{
		offset = 1;
		sign = -1;
	}
	nb = n * sign;
	s = ft_itoabase(nb, "0123456789");
	i = ft_printformatint(sign, sf, s);
	free(s);
	return (i);
}

int	ft_printfu(const char *sf, const unsigned int n)
{
	char	*s;
	int		i;

	s = ft_itoabase(n, "0123456789");
	i = ft_printformat('u', sf, s);
	free(s);
	return (i);
}
