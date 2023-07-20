#include "Serializer.hpp"

int main( void )
{
	
	Data *data1 = new Data();
	data1->name = "FaZe";
	data1->level = 21;
	uintptr_t uintptr;

	std::cout << *data1;
	uintptr = Serializer::serialize(data1);
	std::cout << uintptr << std::endl;
	Data *result = Serializer::deserialize(uintptr);
	std::cout << *result;

	delete data1;
	return (0);
}