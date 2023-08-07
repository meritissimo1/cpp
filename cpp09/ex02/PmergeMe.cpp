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


void PmergeMe::InsertOnVec(std::string n, int index)
{
	int num;
	
	num = std::atoi(n.c_str());
	if (_size % 2 == 0 && index == _size - 1)
		_lastN = num;
	else
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
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	std::vector<int>::iterator nextit;

	it = _listVec.begin();
	ite = _listVec.end();
	nextit = it + 1;

	 while (nextit < ite)
	{
		if (*nextit < *it)
			_pairVec.push_back(std::make_pair(*nextit, *it));
		else
			_pairVec.push_back(std::make_pair(*it, *nextit));
		nextit += 2;
		it += 2;
	}
	 if (it != ite)
		 _pairVec.push_back(std::make_pair(0, *it));
}

bool comparePairs(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    if (p1.second != p2.second) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

void PmergeMe::merge(size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<std::pair<int, int> > leftPairs(n1);
    std::vector<std::pair<int, int> > rightPairs(n2);

    for (size_t i = 0; i < n1; ++i) {
        leftPairs[i] = _pairVec[left + i];
    }
    for (size_t j = 0; j < n2; ++j) {
        rightPairs[j] = _pairVec[mid + 1 + j];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < n1 && j < n2) {
        if (comparePairs(leftPairs[i], rightPairs[j])) {
            _pairVec[k] = leftPairs[i];
            ++i;
        } else {
            _pairVec[k] = rightPairs[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        _pairVec[k] = leftPairs[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        _pairVec[k] = rightPairs[j];
        ++j;
        ++k;
    }

}

void PmergeMe::mergeSort(size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

void PmergeMe::SortLargestPair( void )
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<std::pair<int, int> >::iterator ite;

	it = _pairVec.begin();
	ite = _pairVec.end();

	for (; it != ite; it++)
		std::cout << "[" << it->first << "-" << it->second << "]" << std::endl;
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
			InsertOnVec(_numbers[i], i);

	}
	if (Duplicate())
		throw InvalidDuplicate();
	createGroup();
	mergeSort(0, _pairVec.size() - 1);
	SortLargestPair();
}

