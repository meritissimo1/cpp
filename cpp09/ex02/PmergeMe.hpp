#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cctype>
# include <cstdlib>
# include <ctime>
# include <iomanip>

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
		void printInfos(double time);


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

	class Deque
	{
		public:
			Deque( void );
			Deque(int size, char **numbers);
			Deque(const Deque &d);
			Deque &operator=(const Deque &d);
			~Deque( void );
		
			void Sort( void );
			void InsertOnVec(std::string n);
			int Duplicate( void );
			void createGroup( void );
			void SortLargestPair( void );
			void InsertionSort(std::deque<std::pair<int, int> > &pairDeque, size_t size);
			void createMainPend( void );
			void InsertSorted( void );
			void generatePositions( void );
			void JacobSequence( void );
			int jacobsthal(int n);
			int binarySearch(int target, int begin, int end);
			void printInfos(double time);

		private:
			int									_size;
			char								**_numbers;
			std::deque<int>						_listDeque;
			std::deque<std::pair<int, int> >	_pairDeque;
			std::deque<int>						_dequeMain;
			std::deque<int>						_dequePend;
			std::deque<int>						_jacobSequence;
			std::deque<int>						_positions;
	};

	private:
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
