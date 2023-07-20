#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

typedef unsigned long int uintptr_t;

struct Data
{
	std::string name;
	int			level;
};

class Serializer
{
	public:
		Serializer( void );
		Serializer(const Serializer &s);
		Serializer &operator=(const Serializer &s);
		~Serializer( void );

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &o, Data &d);

#endif