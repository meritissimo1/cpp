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
	_listVec.push_back(num);
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


int	PmergeMe::Duplicate( void )
{
	std::vector<int>::iterator it;	
	std::vector<int>::iterator nextit;	
	std::vector<int>::iterator ite;

	it = _listVec.begin();
	ite = _listVec.end();
	nextit = it + 1;
	for (; it != ite; it++)
	{
		nextit = it + 1;
		for (; nextit != ite; nextit++)
			if (*it == *nextit)
				return (1);
	}
	return (0);
}

void PmergeMe::createGroup( void )
{
	std::vector<std::pair<int, int> > pairVec;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	std::vector<int>::iterator nextit;

	it = _listVec.begin();
	ite = _listVec.end();
	nextit = it + 1;

	 while (nextit < ite)
	{
		if (*nextit < *it)
		{	pairVec.push_back(std::make_pair(*nextit, *it));
			std::cout << *nextit << " < " << *it << std::endl;
		}else{
			pairVec.push_back(std::make_pair(*it, *nextit));
			std::cout << *nextit << " > " << *it << std::endl;
		}
		nextit += 2;
		it += 2;
	}
	 if (it != ite)
		 pairVec.push_back(std::make_pair(0, *it));
	 for (std::vector<std::pair<int, int> >::iterator it = pairVec.begin(); it != pairVec.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
	 std::cout << std::endl;
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
	if (Duplicate())
		throw InvalidDuplicate();
	createGroup();
}

