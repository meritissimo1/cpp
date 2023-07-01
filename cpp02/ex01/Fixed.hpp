#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &copyFixed);
		Fixed &operator=(const Fixed &assignmentFixed);
		~Fixed( void );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					FixedPoint;
		static const int	bits;
};

#endif
