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

	class InvalidInput : public std::exception
	{
		public:
			const char *what() const throw ()
			{
				return ("Error: Invalid Input\n");
			}
	};

	private:
		int _size;
		char **_numbers;
		std::vector<int>	_listVec;
};


#endif
