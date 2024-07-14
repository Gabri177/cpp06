/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:23:18 by yugao             #+#    #+#             */
/*   Updated: 2024/07/13 13:23:19 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv){

	if (argc == 1 || argc > 2){

		std::cerr << "Wrong number of arguments!!!" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}