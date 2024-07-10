#include "ScalarConverter.hpp"

                                    ScalarConverter::ScalarConverter(){}
                                    ScalarConverter::ScalarConverter(const ScalarConverter & obj){}
ScalarConverter &					ScalarConverter::operator=(const ScalarConverter & obj){return *this;}
                                    ScalarConverter::~ScalarConverter(){}



void								ScalarConverter::convert(const std::string & chrs){

    toChar(chrs);
    toInt(chrs);
    toFloat(chrs);
    toDouble(chrs);
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

    if (!isInt(chr) && !isFloat(chr) && !isDouble(chr)){

        std::cout << "char: " << "impossible" << std::endl;
        return ;
    }
    char c = -1;
    if (chr.length() == 1)
        c = chr[0];
    if (isInt(chr) || !isFloat(chr) || !isDouble(chr)){

        try{

            int val = std::stoi(chr);
            if (val >= 0 && val <= 128)
                c = std::stoi(chr);
        }catch(...){}
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
    try {
        int value = std::stoi(chr);
        std::cout << "int: " << value << std::endl;
    }
    catch (std::exception & e){ 
        
        std::cout << "Int: " << "impossible" << std::endl; 
        return;
    }
    
}

void 								ScalarConverter::toFloat(const std::string& chr) {

    if (!isFloat(chr) && !isDouble(chr)){

        std::cout << "Float: " << "impossible" << std::endl;
        return ;
    }
    try{
        
        float value = std::stof(chr);
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    }
    catch (std::exception & e){

        std::cout << "Float: " << "impossible" << std::endl;
        return ;
    }
}

void 								ScalarConverter::toDouble(const std::string& chr) {

    if (!isFloat(chr) && !isDouble(chr)){

        std::cout << "Double: " << "impossible" << std::endl;
        return ;
    }
    try{

        double value = std::stod(chr);
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
    catch (std::exception & e){

        std::cout << "Double: " << "impossible" << std::endl;
        return ;
    }
}
