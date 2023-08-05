#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pm)
{
	if (this != &pm)
		this->_listVec = pm._listVec;
	return (*this);
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe(int size, char **numbers) : _size(size), _numbers(numbers) {}


void PmergeMe::InsertOnVec(std::string n)
{
	int num;

	num = std::atoi(n.c_str());
	std::cout << num + num << std::endl;
}

static int isNumber(std::string number)
{
	size_t i;

	i = 0;
	if (number.empty())
		return(0);
	while (i != number.length())
	{
		if (!std::isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

void PmergeMe::Sort( void )
{
	int i;

	i = 1;
	for (; i < _size; i++)
	{
		if (!isNumber(_numbers[i]))
			throw InvalidInput();
		else
			InsertOnVec(_numbers[i]);

	}
}

