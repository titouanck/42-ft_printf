/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:04:47 by tchevrie          #+#    #+#             */
/*   Updated: 2022/09/22 16:05:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**pstr;
	int		r1;
	int		r2;

	str = "titouanck";
	pstr = &str;
	r1 = printf("Mon telephone est charge a auteur de 42%%.\n");
	r2 = ft_printf("Mon telephone est charge a auteur de 42%%.\n");
	printf("%d : %d\n", r1, r2);

	r1 = printf("J'ai %d ans, bientot %u.\n", 18, 19);
	r2 = ft_printf("J'ai %d ans, bientot %u.\n", 18, 19);
	printf("%d : %d\n", r1, r2);

	r1 = printf("Mes initiales sont %c et %c.\n", (char) 'T', (int) 67);
	r2 = ft_printf("Mes initiales sont %c et %c.\n", (char) 'T', (int) 67);
	printf("%d : %d\n", r1, r2);

	r1 = printf("Je m'appelle %s, et non %s par exemple.\n", "Titouan", "Leo");
	r2 = ft_printf("Je m'appelle %s, et non %s par exemple.\n", "Titouan", "Leo");
	printf("%d : %d\n", r1, r2);

	r1 = printf("On apprends mon pseudo a l'adresse %p : %s.\n", pstr, *pstr);
	r2 = ft_printf("On apprends mon pseudo a l'adresse %p : %s.\n", pstr, *pstr);
	printf("%d : %d\n", r1, r2);

	r1 = printf("En hexadecimal, %d peut s'ecrire %x (ou %X).\n", 42, 42, 42);
	r2 = ft_printf("En hexadecimal, %d peut s'ecrire %x (ou %X).\n", 42, 42, 42);
	printf("%d : %d\n", r1, r2);

	r1 = printf("Voici un ph%rase completement normale.\n");
	r2 = ft_printf("Voici un ph%rase completement normale.\n");
	printf("%d : %d\n", r1, r2);

	r1 = printf("Ma date de naissance est le %d%d.\n", 25, 12);
	r2 = ft_printf("Ma date de naissance est le %d%d.\n", 25, 12);
	printf("%d : %d\n", r1, r2);

}
