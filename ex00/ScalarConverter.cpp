/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:23:23 by yugao             #+#    #+#             */
/*   Updated: 2024/07/14 12:20:13 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

                                    ScalarConverter::ScalarConverter(){}
                                    ScalarConverter::ScalarConverter(const ScalarConverter & obj){*this = obj;}
ScalarConverter &					ScalarConverter::operator=(const ScalarConverter & obj){ (void)obj;return *this;}
                                    ScalarConverter::~ScalarConverter(){}



void								ScalarConverter::convert(const std::string & chrs){

    try{
        toChar(chrs);
    }catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
    try{
        toInt(chrs);
    }catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
    try{
        toFloat(chrs);
    }catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
    try{
        toDouble(chrs);
    }catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
}


bool 								ScalarConverter::isInt(const std::string& chr) {

    char *  end;
    long    val = strtol (chr.c_str(), &end, 10);
    return  *end == '\0' && val > std::numeric_limits<int>::min() && val < std::numeric_limits<int>::max();
}

bool 								ScalarConverter::isFloat(const std::string& chr) {
    
    char *  end;
    strtof (chr.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool 								ScalarConverter::isDouble(const std::string& chr) {
    char *  end;
    strtod(chr.c_str(), &end);
    return *end == '\0';
}

void 								ScalarConverter::toChar(const std::string& chr) {

    if (!isInt(chr) && !isFloat(chr) && !isDouble(chr) && chr.size() != 1){

        std::cout << "char: " << "impossible" << std::endl;
        return ;
    }
    char c = -1;
    if (chr.length() == 1)
        c = chr[0];
    if (isInt(chr) || !isFloat(chr) || !isDouble(chr)){

        char* end;
        errno = 0;
        long val = std::strtol(chr.c_str(), &end, 10);
        if (errno == 0 && (*end == '\0' || *end == 'f' || *end == '.') &&  val >= 0 && val <= 128)
            c = val;
    }
    if (c != -1){
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }else
         std::cout << "char: " << "impossible" << std::endl;
}

void 								ScalarConverter::toInt(const std::string& chr) {

    if (!isInt(chr) && !isFloat(chr) && !isDouble(chr)){

        std::cout << "Int: " << "impossible" << std::endl;
        return ;
    }

    errno = 0;
    char* end;

    long val = static_cast<long>(std::strtod(chr.c_str(), &end));
    //std::cout << val << std::endl;
    if (errno != 0 || (*end != '\0' && *end != 'f' && *end != '.') || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        throw std::runtime_error("Int: impossible");
    std::cout << "Int: " << val << std::endl;
}

void 								ScalarConverter::toFloat(const std::string& chr) {
    
    if (chr == "+inf"){
        std::cout << "Float: " << "+inf" << std::endl;
        return ;
    }
    if (chr == "-inf"){
        std::cout << "Float: " << "-inf" << std::endl;
        return ;
    }
    if (!isFloat(chr) && !isDouble(chr)){

        std::cout << "Float: " << "impossible" << std::endl;
        return ;
    }
    char *end;
    errno = 0;
    float val = std::strtof(chr.c_str(), &end);
    if (errno != 0 || (*end != '\0' && *end !='f') || val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
        throw std::runtime_error("Float: impossible");
    std::cout << "Float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
}

void 								ScalarConverter::toDouble(const std::string& chr) {

    if (chr == "+inf"){
        std::cout << "Float: " << "+inf" << std::endl;
        return ;
    }
    if (chr == "-inf"){
        std::cout << "Float: " << "-inf" << std::endl;
        return ;
    }
    if (!isFloat(chr) && !isDouble(chr)){

        std::cout << "Double: " << "impossible" << std::endl;
        return ;
    }
    char *end;
    errno = 0;
    float val = std::strtod(chr.c_str(), &end);
    if (errno != 0 || (*end != '\0' && *end !='f') || val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
        throw std::runtime_error("Double: impossible");
    std::cout << "Double: " << std::fixed << std::setprecision(1) << val << std::endl;
}
