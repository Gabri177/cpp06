/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:23:26 by yugao             #+#    #+#             */
/*   Updated: 2024/07/13 13:23:27 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_SCALAR_HPP
# define HEAD_SCALAR_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <iomanip>
# include <limits>
# include <errno.h>

class ScalarConverter {

	private:
												ScalarConverter();
												ScalarConverter(const ScalarConverter & obj);
		ScalarConverter &						operator=(const ScalarConverter & obj);
												~ScalarConverter();

		static bool								isInt(const std::string & chrs);
		static bool								isFloat(const std::string & chrs);
		static bool								isDouble(const std::string & chrs);
		static void								toChar(const std::string & chrs);
		static void								toInt(const std::string & chrs);
		static void								toFloat(const std::string & chrs);
		static void								toDouble(const std::string & chrs);

	public:
	
		static void								convert(const std::string & chrs);

};

#endif