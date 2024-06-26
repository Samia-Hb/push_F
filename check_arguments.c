/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:45 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/20 11:20:45 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_type(char **tab)//done
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < ft_strlen(tab[i]))
		{
			if (tab[i][j] < 48 || tab[i][j] > 57)
			{
				if (tab[i][0] != '-' && tab[i][0] != '+')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(long *arr, int argc, char **argv)//done
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < nbr_of_arguments(argc, argv) - 1)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (0);
		j = i + 1;
		while (j < nbr_of_arguments(argc, argv))
		{
			if (arr[i] == arr[j] || arr[j] > INT_MAX || arr[j] < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	nbr_of_arguments(int argc, char **argv)//done
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += ft_counter(argv[i], ' ');
		i++;
	}
	return (count);
}

long	*check_arguments(int argc, char **argv)//done
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	long	*arr;

	i = 1;
	j = 0;
	arr = malloc(nbr_of_arguments(argc, argv));
	if (!arr)
		return (0);
	while (i < argc)
	{
		if (ft_counter(argv[i], ' ') == 0)
			return (0);
		tab = ft_split(argv[i], ' ');
		if (!check_type(tab))
			return (0);
		k = 0;
		while (tab[k])
			arr[j++] = ft_atoi(tab[k++]);
		i++;
	}
	return (arr);
}

int	check_all(int argc, char **argv)//done
{
	long	*arr;

	arr = check_arguments(argc, argv);
	if (nbr_of_arguments(argc, argv) == 1)
		exit(1);
	if (!arr || !check_duplicate(arr, argc, argv))
	{
		ft_printf("Error\n");
		free(arr);
		return (0);
	}
	return (1);
}
