/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:23:35 by yugao             #+#    #+#             */
/*   Updated: 2024/07/13 13:23:36 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_SERIA_HPP
# define HEAD_SERIA_HPP
# include <iostream>
# include <string>

typedef	size_t	uintptr_t;

typedef struct Data {

	int	 			num;
	std::string		str;

}Data;

class Serialization {

	private:
												Serialization();
												~Serialization();
												Serialization(const Serialization&);
    	Serialization& 							operator=(const Serialization&);

	public:

		static uintptr_t						serialize(Data* ptr);
		static Data*							deserialize(uintptr_t raw);
};

#endif