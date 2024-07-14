/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:24:02 by yugao             #+#    #+#             */
/*   Updated: 2024/07/14 12:27:36 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base * generate(void){

	srand(static_cast<unsigned int>(time(0)));
	int val = rand() % 3;
	if (val == 0)
		return new A;
	else if (val == 1)
		return new B;
	else
		return new C;
}

static void identify (Base* p){

	if (dynamic_cast<A*>(p))
		std::cout << "TYPE: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "TYPE: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "TYPE: C" << std::endl;
	else
		std::cout << "TYPE: UNKNOW" << std::endl;
}

static void identify (Base& p){

	try {

		(void)dynamic_cast<A&>(p);
		std::cout << "TYPE: A" << std::endl;
	}catch (std::bad_cast&) {

		try {

			(void)dynamic_cast<B&>(p);
			std::cout << "TYPE: B" << std::endl;
		}catch (std::bad_cast&){

			try {

				(void)dynamic_cast<C&>(p);
				std::cout << "TYPE: C" << std::endl;
			}catch (std::bad_cast&){

				std::cout << "TYPE: UNKNOW" << std::endl;
			}
		}
	}
}


int main (){

	Base* p = generate();
	identify (p);
	identify (*p);
	return 0;
}