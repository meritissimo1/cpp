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

	private:
		int _size;
		char **_numbers;
		std::vector<int>	_listVec;
};


#endif
