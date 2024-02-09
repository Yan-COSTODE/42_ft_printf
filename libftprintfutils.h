/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintfutils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:50 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/08 15:27:00 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTFUTILS_H
# define LIBFTPRINTFUTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int				ft_printfpres(const char c, const char *s, const char *str);
int				ft_printfsign(const int sign, const char *s, const char *str);
char			*ft_strjoin(const char *s1, char *s2);
int				ft_printfwidthafter(const char c, int nb, int len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_printfwidth(const char c, int nb, int *len);
int				ft_printformatint(const int c, const char *s, const char *str);
int				ft_printformat(const char c, const char *s, const char *str);
void			*ft_callocb(size_t nmemb, size_t size);
size_t			ft_strlen(const char *s);
unsigned int	ft_atoui(const char *s);
char			*ft_strchrs(const char *s1, const char *s2);
char			*ft_itoabase(size_t n, const char *base);
void			ft_printfnc(const char c, int n);
int				ft_printfc(const char *sf, const char c);
int				ft_printfs(const char *sf, const char *s1);
int				ft_printfp(const char *sf, void	*ptr);
int				ft_printfdi(const char *sf, int n);
int				ft_printfu(const char *sf, const unsigned int n);
int				ft_printfx(const char *sf, const unsigned int n);
int				ft_printfxx(const char *sf, const unsigned int n);
int				ft_printfpct(void);

#endif
