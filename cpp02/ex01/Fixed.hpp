#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &copyFixed);
		Fixed &operator=(const Fixed &assignmentFixed);
		~Fixed( void );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					FixedPoint;
		static const int	bits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &Obj);

#endif
