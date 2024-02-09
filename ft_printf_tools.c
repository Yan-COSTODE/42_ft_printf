/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:39:18 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/09 14:50:10 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintfutils.h"

static void	ft_printfformatintbis(int sign, int *nb, int *len, const char *s)
{
	if (s[0] != '0' && s[0] != '-' && s[0] != '.')
		*nb = ft_atoui(&s[0]);
	else
		*nb = ft_atoui(&s[1]);
	if ((s[0] == '0' || s[0] == '.') && sign == -1)
	{
		write(1, "-", 1);
		*len = *len + 1;
	}
}

int	ft_printformatint(const int sign, const char *s, const char *str)
{
	int	len;
	int	nb;
	int	size;

	len = 0;
	size = ft_strlen(str);
	if (sign == -1)
		++size;
	ft_printfformatintbis(sign, &nb, &len, s);
	len += ft_printfwidth(s[0], nb, &size);
	len += ft_printfpres('d', ft_strchrs(s, "."), str);
	len += ft_printfsign(sign, ft_strchrs(s, "+"), ft_strchrs(s, " "));
	if (!(s[0] == '0' || s[0] == '.') && sign == -1)
	{
		write(1, "-", 1);
		++len;
	}
	if (!(nb == 0 && s[0] == '.'))
	{
		write(1, str, ft_strlen(str));
		len += ft_strlen(str);
	}
	ft_printfwidthafter(s[0], nb, size);
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	length;
	size_t	i;

	if (start >= ft_strlen(s))
		length = 0;
	else if (len < ft_strlen(s))
		length = len;
	else
		length = ft_strlen(s);
	ptr = (char *)ft_callocb((length + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < length && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_printfwidthafter(const char c, int nb, int len)
{
	if (c == '-')
		ft_printfnc(' ', nb - len);
	if (nb > len)
		return (nb - len);
	else
		return (0);
}

char	*ft_strjoin(const char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = ft_callocb(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		s[i + j] = s2[j];
		++j;
	}
	free(s2);
	return (s);
}
