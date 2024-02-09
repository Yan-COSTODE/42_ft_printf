/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:10:07 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/09 14:40:35 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfutils.h"

int	ft_printfwidth(const char c, int nb, int *len)
{
	int	tmp;

	if (c == '.')
		return (0);
	tmp = *len;
	if (c == '0')
		ft_printfnc('0', nb - *len);
	if ((c >= '1' && c <= '9') || c == ' ')
		ft_printfnc(' ', nb - *len);
	if (nb > *len)
		return (nb - tmp);
	else
		return (0);
}

int	ft_printfpres(const char c, const char *s, const char *str)
{
	int	nb;
	int	len;

	len = ft_strlen(str);
	if (c == 's')
	{
		if (!s)
		{
			write(1, str, len);
			return (len);
		}
		nb = ft_atoui(&s[1]);
		if (len > nb)
			len = nb;
		write(1, str, len);
		return (len);
	}
	else
	{
		if (s)
			return (ft_printfwidth('0', ft_atoui(&s[1]), &len));
	}
	return (0);
}

int	ft_printfsign(const int sign, const char *s, const char *str)
{
	if (s)
	{
		if (sign == 1)
			write(1, "+", 1);
		else
			return (0);
		return (1);
	}
	else if (str)
	{
		if (sign == 1)
			write(1, " ", 1);
		else
			return (0);
		return (1);
	}
	return (0);
}

static int	ft_printfhashtag(const char c, const char *s)
{
	if (s[0] == '0' && s[1] == 0)
		return (0);
	write(1, "0", 1);
	write(1, &c, 1);
	return (2);
}

int	ft_printformat(const char c, const char *s, const char *str)
{
	int	len;
	int	nb;
	int	size;

	len = 0;
	size = ft_strlen(str);
	if (s[0] != '0' && s[0] != '-' && s[0] != '.' && s[0] != ' ')
		nb = ft_atoui(&s[0]);
	else
		nb = ft_atoui(&s[1]);
	len += ft_printfwidth(s[0], nb, &size);
	if (c != 'c' && c != 's')
		len += ft_printfpres('d', ft_strchrs(s, "."), str);
	if ((c == 'x' || c == 'X') && ft_strchrs(s, "#"))
		len += ft_printfhashtag(c, str);
	if (c != 's')
	{
		write(1, str, ft_strlen(str));
		len += ft_strlen(str);
	}
	else
		len += ft_printfpres('s', ft_strchrs(s, "."), str);
	ft_printfwidthafter(s[0], nb, ft_strlen(str));
	return (len);
}
