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

template <typename T>
bool isSorted(T &_list)
{
	size_t	i;

	i = 1;
	for (; i < _list.size(); ++i)
		if (_list[i] < _list[i - 1])
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
	if (target > _vecMain.at(mid))
		return (mid + 1);
	else
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

void PmergeMe::printInfos(double time)
{
	std::cout << "Before:\t";
	for (size_t i = 0; i < _listVec.size(); i++)
		std::cout << _listVec[i] << " ";
	std::cout << std::endl;
	std::cout << "After:\t";
	for (size_t j = 0; j < _vecMain.size(); j++)
		std::cout << _vecMain[j] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _listVec.size() << " elements with std::vector: " <<
		std::fixed << std::setprecision(6) << time * 1000000 << " us" << std::endl;
}

void PmergeMe::Sort( void )
{
	int i;

	i = 1;
	clock_t startTime;
	for (; i < _size; i++)
	{
		if (!isNumber(_numbers[i]))
			throw InvalidInput();
		else
		{
			InsertOnVec(_numbers[i]);
			startTime = clock();
		}	
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
	clock_t endTime = clock();
	double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	printInfos(time);
	//SortLargestPair(); // servindo de print
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

PmergeMe::Deque::Deque( void ) {}

PmergeMe::Deque::Deque(const Deque &pm)
{
	*this = pm;
}

PmergeMe::Deque &PmergeMe::Deque::operator=(const Deque &d)
{
	if (this != &d)
	{
		this->_size = d._size;
		this->_numbers = d._numbers;
	}	
	return (*this);
}

PmergeMe::Deque::~Deque( void ) {}

PmergeMe::Deque::Deque(int size, char **numbers) : _size(size), _numbers(numbers) {}

void PmergeMe::Deque::InsertOnVec(std::string n)
{
	int num;

	num = std::atoi(n.c_str());
	if (num < 0 )
		throw IntOutOfBounds();
	_listDeque.push_back(num);
}



int	PmergeMe::Deque::Duplicate( void )
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator nextit;
	std::deque<int>::iterator ite;

	it = _listDeque.begin();
	ite = _listDeque.end();
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

void PmergeMe::Deque::createGroup( void )
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator ite;
	std::deque<int>::iterator nextit;
	int i;

	it = _listDeque.begin();
	ite = _listDeque.end();
	nextit = it + 1;
	i =_listDeque.size() / 2;

	while (i != 0)
	{
		if (*nextit < *it)
			_pairDeque.push_back(std::make_pair(*it, *nextit));
		else
			_pairDeque.push_back(std::make_pair(*nextit, *it));
		nextit += 2;
		it += 2;
		i--;
	}
}

void PmergeMe::Deque::InsertionSort(std::deque<std::pair<int, int> > &pairDeque, size_t size)
{
	if (size <= 1)
		return;
	InsertionSort(pairDeque, size - 1);
	size_t nextPair = size - 1;
	std::pair<int, int> auxPair = pairDeque[nextPair];
	int j = static_cast<int>(nextPair) - 1;
	while (j >= 0 && pairDeque[j] > auxPair)
	{
		pairDeque[j + 1] = pairDeque[j];
		--j;
	}
	pairDeque[j + 1] = auxPair;
}

void PmergeMe::Deque::createMainPend( void )
{
	std::deque<std::pair<int, int> >::iterator it;
	std::deque<std::pair<int, int> >::iterator ite;

	it = _pairDeque.begin();
	ite = _pairDeque.end();
	_dequeMain.insert(_dequeMain.begin(), it->second);
	while(it != ite)
	{
		_dequeMain.push_back(it->first);
		_dequePend.push_back(it->second);
		it++;
	}
}

int PmergeMe::Deque::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::Deque::JacobSequence( void )
{
	int size;
	int jacobI;

	size = this->_dequePend.size();
	jacobI = 3;
	while ((this->jacobsthal(jacobI)) < size - 1)
	{
		this->_jacobSequence.push_back(this->jacobsthal(jacobI));
		jacobI++;
	}
}

void PmergeMe::Deque::generatePositions( void )
{
	size_t lastjacobN;
	size_t posNotJacob;
	size_t lastjacobAux;
	size_t i;

	if (this->_dequePend.empty())
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
	while (lastjacobN++ < this->_dequePend.size())
		this->_positions.push_back(lastjacobN);
}

int PmergeMe::Deque::binarySearch(int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target > _dequeMain.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > _dequeMain.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::Deque::InsertSorted( void )
{
	std::deque<int>::iterator it;
	int target;
	size_t addedCount;
	size_t pos;

	addedCount = 0;

	for (it = this->_positions.begin(); it < this->_positions.end(); it++)
	{
		target = this->_dequePend.at(*it - 1);

		pos = this->binarySearch(target, 0, *it + addedCount);
		this->_dequeMain.insert(this->_dequeMain.begin() + pos, target);
		addedCount++;
	}
	if (this->_listDeque.size() % 2 != 0)
	{
		target = this->_listDeque.at(this->_listDeque.size() - 1);
		pos = this->binarySearch(target, 0, this->_dequeMain.size() - 1);
		this->_dequeMain.insert(this->_dequeMain.begin() + pos, target);
	}
}

void PmergeMe::Deque::printInfos(double time)
{
//	std::cout << "Before: ";
//	for (size_t i = 0; i < _listDeque.size(); i++)
//		std::cout << _listDeque[i] << " ";
//	std::cout << std::endl;
//	std::cout << "After: ";
//	for (size_t j = 0; j < _dequeMain.size(); j++)
//		std::cout << _dequeMain[j] << " ";
//	std::cout << std::endl;
	std::cout << "Time to process a range of " << _listDeque.size() << " elements with std::deque:  " <<
		std::fixed << std::setprecision(6) << time * 1000000 << " us" << std::endl;
}

void PmergeMe::Deque::Sort( void )
{
	int i;

	i = 1;
	clock_t	startTime;
	for (; i < _size; i++)
	{
		if (!isNumber(_numbers[i]))
			throw InvalidInput();
		else
		{
			InsertOnVec(_numbers[i]);
			startTime = clock();
		}
	}
	if (Duplicate())
		throw InvalidDuplicate();
	else if (_listDeque.size() == 1)
		throw OnlyOneParam();
	else if(isSorted(_listDeque))
		throw IsSorted();
	createGroup();
	InsertionSort(_pairDeque, _pairDeque.size());
	createMainPend();
	JacobSequence();
	generatePositions();
	InsertSorted();
	clock_t endTime = clock();
	double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	printInfos(time);
	//SortLargestPair(); // servindo de print
}



void PmergeMe::Deque::SortLargestPair( void )
{
	std::deque<std::pair<int, int> >::iterator it;
	std::deque<std::pair<int, int> >::iterator ite;

	it = _pairDeque.begin();
	ite = _pairDeque.end();

	std::cout << "Pair deque\n";
	for (; it != ite; it++)
		std::cout << "[" << it->first << "-" << it->second << "]" << std::endl;
	std::cout << "\nMain deque\n";
	std::deque<int>::iterator begin;
	std::deque<int>::iterator end;
	
	
	begin = _dequeMain.begin();
	end = _dequeMain.end();
	--end;
	for (; begin <= end; begin++)
		std::cout << "[" << *begin << "] ";
	
	
	begin = _dequePend.begin();
	end = _dequePend.end();
	--end;
	std::cout << "\n\nPend deque\n";
	for (; begin <= end; begin++)
		std::cout << "[" << *begin << "] ";
	std::cout << std::endl;


	for (unsigned int i = 0; i < _dequeMain.size(); i++)
		std::cout << this->_dequeMain.at(i) << " ";
	std::cout << std::endl;
}

