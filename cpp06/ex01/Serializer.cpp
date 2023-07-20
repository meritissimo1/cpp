#include "Serializer.hpp"

Serializer::Serializer( void )
{
	std::cout << "Default constructor called\n";
}

Serializer::Serializer (Serializer const &s)
{
	std::cout << "Copy constructor called\n";
	*this = s;
}

Serializer & Serializer::operator=(Serializer const &s)
{
	std::cout << "Copy assignmet operator called\n";
	if (this != &s)
		*this = s;
	return (*this);
}

Serializer::~Serializer ( void )
{
	std::cout << "Destructor called\n";
}

std::ostream &operator<<(std::ostream &o, Data &d)
{
	o << "name: " << d.name << std::endl << "level: " << d.level << std::endl;
	return o;
}


uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t result;

	result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *result;

	result = reinterpret_cast<Data *>(raw);
	return (result);
}
