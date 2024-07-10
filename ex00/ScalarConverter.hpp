#ifndef HEAD_SCALAR_HPP
# define HEAD_SCALAR_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <iomanip>

class ScalarConverter {

	private:
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