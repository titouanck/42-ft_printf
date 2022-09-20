/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:03:45 by tchevrie          #+#    #+#             */
/*   Updated: 2022/09/21 00:38:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/includes/libft.h"

// static size_t	count_args(const char *str)
// {
// 	size_t	count;
// 	int		previous_arg;
// 	size_t	i;

// 	count = 0;
// 	previous_arg = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && !previous_arg)
// 		{
// 			previous_arg = 1;
// 			count++;
// 		}
// 		else if (str[i] == '%' && previous_arg)
// 		{
// 			count--;
// 			previous_arg = 0;
// 		}
// 		else
// 			previous_arg = 0;
// 		i++;
// 	}
// 	return (count);
// }

static size_t	conversion(const char *c, size_t *i, va_list *ap)
{
	if (*c != '%')
	{	
		ft_putchar(*c);
		return (0);
	}
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
	else if (*(c + 1) == '%')
		return (-2 + ft_putchar('%'));
	else if (*(c + 1) >= '\a' && '\r' >= *(c + 1))
		return (-2 + ft_putchar(*(c + 1)));
	return (-2);
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

// int	main(void)
// {
// 	ft_printf(" (%d)", ft_printf("(ft_...) %s !", "Titouan"));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %d !", 42));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %i !", -21));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %p !", "Hello"));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %s !", "Titouan"));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %\n %p !", 4294967295));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %%%u !", 4294967296));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %c !", 4));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %p !", 4));
// 	ft_putstr("\n");
// 	ft_printf(" (%d)", ft_printf("(ft_...) %s !", NULL));
// 	ft_putstr("\n");

// 	printf("\n\n");

// 	printf(" (%d)", printf("(printf) %s !", "Titouan"));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %d !", 42));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %i !", -21));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %p !", "Hello"));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %s !", "Titouan"));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %\n %p !", 4294967295));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %%%u !", 4294967296));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %c !", 4));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %p !", 4));
// 	printf("\n");
// 	printf(" (%d)", printf("(printf) %s !", NULL));
// 	printf("\n");
// }
