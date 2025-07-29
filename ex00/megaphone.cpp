/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:41:50 by dario             #+#    #+#             */
/*   Updated: 2025/07/29 21:01:50 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	j;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			j = -1;
			while (argv[i][++j])
			std::cout << static_cast<unsigned char>(toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
