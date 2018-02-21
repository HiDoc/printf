/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:36:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/21 18:34:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <float.h>
#include <time.h>
#include "libftprintf.h"

int		test_f(float f)
{
	char	std1[5000];
	char	std2[5000];
	printf("TEST float : \n");
	int a = ft_printf("%f\n", f);
	gets(std1);
	int b = printf("%f\n", f);
	gets(std2);
	printf("return a : %d, return b : %d\n\n", a, b);
	return (a != b && !ft_strcmp(std1, std2));
}

int		test_d(double f)
{
	char	std1[5000];
	char	std2[5000];
	printf("TEST double : \n");
	int a = ft_printf("%F\n", f);
	gets(std1);
	int b = printf("%F\n", f);
	printf("return a : %d, return b : %d\n\n", a, b);
	gets(std2);
	return (a != b && !ft_strcmp(std1, std2));
}

void 	launch_test(int num)
{
	int		count;
	int		error;
	double	random_f;
	float 	a;
   
	a = 5.0;
	random_f = 0;
	count = 0;
	error = 0;
	srand((unsigned int)time(NULL));
	while (count < num)
	{
		random_f = ((double)rand()/(double)(RAND_MAX/a));
		error += test_f(random_f);
		error += test_d(random_f);
		count++;
	}	
	printf("%s\n", !error ? "Aucune erreur" : "Erreur");
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		launch_test(ft_atoi(argv[1]));
	return (0);
}
