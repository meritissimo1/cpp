#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <iomanip>


template <typename T>
void iter(T *address, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(address[i]);
}

#endif
