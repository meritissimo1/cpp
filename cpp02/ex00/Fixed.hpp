#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed( void );
		Fixed(const Fixed &copyFixed);
		Fixed &operator=(const Fixed &assignmentFixed);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					FixedPoint;
		static const int	bits;
};

#endif
