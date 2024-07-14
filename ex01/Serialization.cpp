/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:23:32 by yugao             #+#    #+#             */
/*   Updated: 2024/07/13 13:23:33 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"


								Serialization::Serialization(){}
								Serialization::~Serialization(){}
								Serialization::Serialization(const Serialization&){}
Serialization& 					Serialization::operator=(const Serialization&){return *this;}


uintptr_t						Serialization::serialize(Data* ptr){

	return reinterpret_cast<uintptr_t>(ptr);
}

Data*							Serialization::deserialize(uintptr_t raw){

	return reinterpret_cast<Data*>(raw);
}