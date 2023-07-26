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

template <typename T>
void	easyfind(T &container, int needle)
{
	std::list<int>::iterator it;

	it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw ValueNotFound();
	std::cout << "Value found - " << *it << std::endl;

}

#endif
