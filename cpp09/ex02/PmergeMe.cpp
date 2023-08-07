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
			_pairVec.push_back(std::make_pair(*it, *nextit));
		else
			_pairVec.push_back(std::make_pair(*nextit, *it));
		nextit += 2;
		it += 2;
	}
	 if (it != ite)
		 _pairVec.push_back(std::make_pair(0, *it));
}


void merge(std::vector<std::pair<int, int> >& arr, size_t left, size_t mid, size_t right)
{
    size_t leftSize; 
    size_t rightSize;
   
    rightSize = right - mid;
    leftSize = mid - left + 1;
    std::vector<std::pair<int, int> > leftArr(leftSize);
    std::vector<std::pair<int, int> > rightArr(rightSize);

    for (size_t i = 0; i < leftSize; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for (size_t i = 0; i < rightSize; ++i)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    size_t leftIndex = 0, rightIndex = 0, mergeIndex = left;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
	{
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
	else
	{
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    while (leftIndex < leftSize)
    {
        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while (rightIndex < rightSize)
    {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}

void mergeSort(std::vector<std::pair<int, int> >& arr, size_t left, size_t right)
{
	if (left < right)
	{
        	size_t mid = left + (right - left) / 2;
        	mergeSort(arr, left, mid);
        	mergeSort(arr, mid + 1, right);
        	merge(arr, left, mid, right);
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
	mergeSort(_pairVec, 0, _pairVec.size() -1);


	SortLargestPair();
}

