#include "Serialization.hpp"


int main (){

	Data test;
	test.num = 123;
	test.str = "jajaja";

	Data nuevo = *Serialization::deserialize(Serialization::serialize(&test));
	std::cout << "num:  " << nuevo.num << "; str:  " << nuevo.str << std::endl;
	return 0;	
}