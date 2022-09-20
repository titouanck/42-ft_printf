// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_ft_printf.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/20 18:02:00 by tchevrie          #+#    #+#             */
// /*   Updated: 2022/09/20 21:19:15 by tchevrie         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdarg.h>
// #include <stdio.h>
// #include "libft/includes/libft.h"
// #define FTPRINT ft_printf

// int	ft_printf(const char *str, ...);

// int	main(int argc, char **argv)
// {
// 	char			*firstname = "Titouan";
// 	char			lastname[] = "Chevrier";
// 	int				age = 18;
// 	int				*ptr = &age;
// 	int				tab[] = {4, 8, 15, 16, 23, 42};
// 	size_t			count = 19;
// 	unsigned int	majority = 21;
// 	char			*vide = "";

// 		FTPRINT("%s\n", firstname);
// 		FTPRINT("%s\n", lastname);
// 		FTPRINT("%d - %x - %X\n", age, age, age);
// 		FTPRINT("%p - %i - %X - %x\n", ptr, *ptr, *ptr, *ptr);
// 		FTPRINT("wegrpe[33340504 %d%%. %i\n", 42, tab[0]);
// 		FTPRINT("%i, %u\n", majority, majority - 3);
// 		FTPRINT("%p - %s\n", vide, vide);
// 		FTPRINT("%p %s\n", NULL, NULL);
// 		FTPRINT("%p %s\n", 0, 0);
// 		printf("%s\n", firstname);
// 		printf("%s\n", lastname);
// 		printf("%d - %x - %X\n", age, age, age);
// 		printf("%p - %i - %X - %x\n", ptr, *ptr, *ptr, *ptr);
// 		printf("wegrpe[33340504 %d%%. %i\n", 42, tab[0]);
// 		printf("%i, %u\n", majority, majority - 3);
// 		printf("%p - %s\n", vide, vide);
// 		printf("%p %s\n", NULL, NULL);
// 		printf("%p %s\n", 0, 0);
// }
