/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilsa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:30:55 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/06 11:37:41 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfutils.h"

int	ft_printfx(const char *sf, const unsigned int n)
{
	char	*s;
	int		i;

	s = ft_itoabase(n, "0123456789abcdef");
	i = ft_printformat('x', sf, s);
	free(s);
	return (i);
}

int	ft_printfxx(const char *sf, const unsigned int n)
{
	char	*s;
	int		i;

	s = ft_itoabase(n, "0123456789ABCDEF");
	i = ft_printformat('X', sf, s);
	free(s);
	return (i);
}

int	ft_printfpct(void)
{
	write(1, "%", 1);
	return (1);
}

char	*ft_itoabase(size_t n, const char *base)
{
	char	*s;
	size_t	len;
	size_t	nb;
	size_t	blen;

	len = 1;
	blen = ft_strlen(base);
	nb = n;
	while (nb / blen > 0)
	{
		nb /= blen;
		len++;
	}
	s = (char *) ft_callocb(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	s[0] = '0';
	while (n > 0)
	{
		s[--len] = base[n % blen];
		n /= blen;
	}
	return (s);
}

char	*ft_strchrs(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	if (s2[0] == 0)
		return ((char *)&s1[i]);
	return (NULL);
}
