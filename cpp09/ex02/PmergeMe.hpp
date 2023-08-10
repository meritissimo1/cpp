#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cctype>
# include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe(int size, char **numbers);
		PmergeMe(const PmergeMe &pm);
		PmergeMe &operator=(const PmergeMe &pm);
		~PmergeMe( void );
	
		void Sort( void );
		void InsertOnVec(std::string n);
		int Duplicate( void );
		void createGroup( void );
		void SortLargestPair( void );
		void InsertionSort(std::vector<std::pair<int, int> > &_pairVec, size_t size);
		void createMainPend( void );
		void InsertSorted( void );
		void generatePositions( void );
		void JacobSequence( void );
		int jacobsthal(int n);
		int binarySearch(int target, int begin, int end);



	class InvalidInput : public std::exception
	{
		public:
			const char *what() const throw ()
			{
				return ("Error: Invalid Input\n");
			}
	};
	class InvalidDuplicate : public std::exception
	{
		public:
			const char *what() const throw ()
			{
				return ("Error: Duplicate values\n");
			}
	};

	class OnlyOneParam : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return ("Warning: Only one Parameter\n");
			}
	};

	class IsSorted : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return("Warning: The sequence is already sorted\n");
		}
	};

	class IntOutOfBounds : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Error: number too large\n");
		}
	};

	private:
		bool								_hasJacob;
		int									_size;
		char								**_numbers;
		std::vector<int>					_listVec;
		std::vector<std::pair<int, int> >	_pairVec;
		std::vector<int>					_vecMain;
		std::vector<int>					_vecPend;
		std::vector<int>					_jacobSequence;
		std::vector<int>					_positions;
};

#endif