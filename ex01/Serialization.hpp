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