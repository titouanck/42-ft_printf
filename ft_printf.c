/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:03:45 by tchevrie          #+#    #+#             */
/*   Updated: 2022/09/22 16:05:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	conversion(const char *c, size_t *i, va_list *ap)
{
	if (*c != '%')
		return (-1 + ft_putchar(*c));
	*i = *i + 1;
	if (*(c + 1) == 'c')
		return (-2 + ft_putchar((char) va_arg(*ap, int)));
	else if (*(c + 1) == 's')
		return (-2 + ft_putstr(va_arg(*ap, const char *)));
	else if (*(c + 1) == 'p')
		return (-2 + ft_putadress(va_arg(*ap, void *)));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (-2 + ft_putnbr(va_arg(*ap, int)));
	else if (*(c + 1) == 'u')
		return (-2 + ft_putunbr(va_arg(*ap, unsigned int)));
	else if (*(c + 1) == 'x')
		return (-2 + ft_puthexa_lower(va_arg(*ap, int)));
	else if (*(c + 1) == 'X')
		return (-2 + ft_puthexa_upper(va_arg(*ap, int)));
	else
		return (-2 + ft_putchar(*(c + 1)));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	size_t	i;

	len = ft_strlen(str);
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		len += conversion(str + i, &i, &ap);
		i++;
	}
	va_end(ap);
	return (len);
}
