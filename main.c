/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:06:34 by trobbin           #+#    #+#             */
/*   Updated: 2019/10/16 01:00:09 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int file_d;
	char *text;

	text = (char *)malloc(sizeof(char) * 512);
	if (argc == 2)
	{
		file_d = open(argv[argc - 1], O_RDONLY);
		get_next_line(file_d, &text);
		printf("%s\n", text);

		get_next_line(file_d, &text);
		printf("%s\n", text);

		get_next_line(file_d, &text);
		printf("%s\n", text);
	}
	return (0);
}
