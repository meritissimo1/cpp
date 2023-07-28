#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void ) {};
		MutantStack(const MutantStack &ms)
		{
			*this = ms;
		}
		MutantStack &operator=(const MutantStack &ms)
		{
			if (this != &ms)
				*this = ms;
			return (*this);
		}
		~MutantStack( void ) {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}



};

#endif
