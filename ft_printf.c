/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:55:39 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/09 15:01:15 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_selector(const char c, const char *s, va_list args)
{
	(void)s;
	if (c == 'c')
		return (ft_printfc(s, (char) va_arg(args, int)));
	if (c == 's')
		return (ft_printfs(s, va_arg(args, char *)));
	if (c == 'p')
		return (ft_printfp(s, va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printfdi(s, va_arg(args, int)));
	if (c == 'u')
		return (ft_printfu(s, va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_printfx(s, va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_printfxx(s, va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_printfpct());
	return (0);
}

static int	ft_printfft(const char *s, unsigned int n, va_list args, size_t *i)
{
	int		res;
	char	*str;

	*i = *i + 1;
	if (n == 0)
		return (0);
	str = ft_substr(s, 0, n);
	res = ft_selector(s[n - 1], str, args);
	free(str);
	return (res);
}

static int	ft_printfln(const char *s)
{
	char	*ptr;

	ptr = ft_strchrs(&s[1], "cspdiuxX%");
	if (!ptr)
		return (0);
	return (ptr - s);
}

int	ft_printf(const char *s, ...)
{
	size_t	len;
	size_t	i;
	int		ot;
	va_list	args;
	int		ln;

	len = ft_strlen(s);
	i = 0;
	ot = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			ln = ft_printfln(&s[i]);
			ot += ft_printfft(&s[i + 1], ln, args, &i) - 1;
			i += ln - 1;
		}
		else
			write(1, &s[i], 1);
		++ot;
		++i;
	}
	va_end(args);
	return (ot);
}
