/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:23:29 by yugao             #+#    #+#             */
/*   Updated: 2024/07/13 13:23:30 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"


int main (){

	Data test;
	test.num = 123;
	test.str = "jajaja";

	Data nuevo = *Serialization::deserialize(Serialization::serialize(&test));
	std::cout << "num:  " << nuevo.num << "; str:  " << nuevo.str << std::endl;
	return 0;	
}