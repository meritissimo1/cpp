#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <algorithm>

class ValueNotFound : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Value not found\n");
		}
};

template <class T>
void	easyfind(T &container, int i)
{
	std::list<int>::const_iterator it = container.begin();
	std::list<int>::const_iterator ite = container.end();
	int pos = 1;

	for (; it != ite; it++)
	{
		if (*it == i)
		{
			std::cout << "Value [" << *it << "] found in " << pos << "° position" << std::endl;
			return ;
		}
		pos++;
	}
	throw ValueNotFound();
}

#endif
