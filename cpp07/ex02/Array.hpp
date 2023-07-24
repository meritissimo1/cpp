#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array( void )
		{
			this->_arr = NULL;
			this->len = 0;
		}

		Array(unsigned int n) 
		{
			this->_arr = NULL;
			this->len = n;
			if(n)
				this->_arr = new T[n];
		}
		Array(const Array<T> &a)
		{
			*this = a;
		}
		Array<T> &operator=(const Array<T> &a)
		{
			std::cout << "Operator = called\n";

			if (this != &a)
			{
				this->_arr = new T[a.len];
				for (unsigned int i = 0; i < a.len; i++)
					this->_arr[i] = a._arr[i];
				this->len = a.len;
			}
			return (*this);
		}
		T &operator[](size_t i)
		{
			if (i >= this->len)
				throw IndexOutOfBounds();
			return (this->_arr[i]);
		}

		class IndexOutOfBounds : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Index out of bounds\n";
				}
		};

		size_t size( void ) const
		{
			return (this->len);
		}

		~Array( void )
		{
			if (this->_arr)
				delete [] this->_arr;
			this->_arr = NULL;
			this->len = 0;
		}


	private:
		T *_arr;
		unsigned int len;
};

#endif
