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
	if (num < 0 )
		throw IntOutOfBounds();
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

bool isSorted(std::vector<int> &nums)
{
	size_t	i;

	i = 1;
	for (; i < nums.size(); ++i)
		if (nums[i] < nums[i - 1])
			return (false);
	return (true);
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
	int i;

	it = _listVec.begin();
	ite = _listVec.end();
	nextit = it + 1;
	i =_listVec.size() / 2;

	while (i != 0)
	{
		if (*nextit < *it)
			_pairVec.push_back(std::make_pair(*it, *nextit));
		else
			_pairVec.push_back(std::make_pair(*nextit, *it));
		nextit += 2;
		it += 2;
		i--;
	}
}

void PmergeMe::InsertionSort(std::vector<std::pair<int, int> > &pairVec, size_t size)
{
	if (size <= 1)
		return;
	InsertionSort(pairVec, size - 1);
	size_t nextPair = size - 1;
	std::pair<int, int> auxPair = pairVec[nextPair];
	int j = static_cast<int>(nextPair) - 1;
	while (j >= 0 && pairVec[j] > auxPair)
	{
		pairVec[j + 1] = pairVec[j];
		--j;
	}
	pairVec[j + 1] = auxPair;
}

void PmergeMe::createMainPend( void )
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<std::pair<int, int> >::iterator ite;

	it = _pairVec.begin();
	ite = _pairVec.end();
	_vecMain.insert(_vecMain.begin(), it->second);
	while(it != ite)
	{
		_vecMain.push_back(it->first);
		_vecPend.push_back(it->second);
		it++;
	}
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::JacobSequence( void )
{
	int size;
	int jacobI;

	size = this->_vecPend.size();
	jacobI = 3;
	while ((this->jacobsthal(jacobI)) < size - 1)
	{
		this->_jacobSequence.push_back(this->jacobsthal(jacobI));
		jacobI++;
		_hasJacob = true;
	}
}

void PmergeMe::generatePositions( void )
{
	size_t lastjacobN;
	size_t posNotJacob;
	size_t lastjacobAux;
	size_t i;

	if (this->_vecPend.empty())
		return;
	lastjacobAux = 1;
	lastjacobN = 1;
	i = 0;
	while (i < this->_jacobSequence.size())
	{
		lastjacobN = this->_jacobSequence.at(i);
		this->_positions.push_back(lastjacobN);
		posNotJacob = lastjacobN - 1;
		while (posNotJacob > lastjacobAux)
		{
			this->_positions.push_back(posNotJacob);
			posNotJacob--;
		}
		lastjacobAux = lastjacobN;
		i++;
	}
	while (lastjacobN++ < this->_vecPend.size())
		this->_positions.push_back(lastjacobN);
}

int PmergeMe::binarySearch(int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target > _vecMain.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	return (mid);
}

void PmergeMe::InsertSorted( void )
{
	std::vector<int>::iterator it;
	int target;
	size_t addedCount;
	size_t pos;

	addedCount = 0;

	for (it = this->_positions.begin(); it < this->_positions.end(); it++)
	{
		target = this->_vecPend.at(*it - 1);

		pos = this->binarySearch(target, 0, *it + addedCount);
		this->_vecMain.insert(this->_vecMain.begin() + pos, target);
		addedCount++;
	}
	if (this->_listVec.size() % 2 != 0)
	{
		target = this->_listVec.at(this->_listVec.size() - 1);
		pos = this->binarySearch(target, 0, this->_vecMain.size() - 1);
		this->_vecMain.insert(this->_vecMain.begin() + pos, target);
	}
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
	else if (_listVec.size() == 1)
		throw OnlyOneParam();
	else if(isSorted(_listVec))
		throw IsSorted();
	createGroup();
	InsertionSort(_pairVec, _pairVec.size());
	createMainPend();
	JacobSequence();
	generatePositions();
	InsertSorted();

	SortLargestPair(); // servindo de print
}

void PmergeMe::SortLargestPair( void )
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<std::pair<int, int> >::iterator ite;

	it = _pairVec.begin();
	ite = _pairVec.end();

	std::cout << "Pair vec\n";
	for (; it != ite; it++)
		std::cout << "[" << it->first << "-" << it->second << "]" << std::endl;
	std::cout << "\nMain vec\n";
	std::vector<int>::iterator begin;
	std::vector<int>::iterator end;
	
	
	begin = _vecMain.begin();
	end = _vecMain.end();
	--end;
	for (; begin <= end; begin++)
		std::cout << "[" << *begin << "] ";
	
	
	begin = _vecPend.begin();
	end = _vecPend.end();
	--end;
	std::cout << "\n\nPend vec\n";
	for (; begin <= end; begin++)
		std::cout << "[" << *begin << "] ";
	std::cout << std::endl;


	for (unsigned int i = 0; i < _vecMain.size(); i++)
		std::cout << this->_vecMain.at(i) << " ";
	std::cout << std::endl;
}
