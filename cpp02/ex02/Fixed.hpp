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

		int		getRawBits( void ) const;
		void	setRawBits(int const raw);

		Fixed	&operator=(const Fixed &fixed);

		float	operator*(const Fixed &fixed) const;
		float	operator+(const Fixed &fixed) const;
		float	operator-(const Fixed &fixed) const;
		float	operator/(const Fixed &fixed) const;

		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;	
		
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed	&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed	&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
		~Fixed( void );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					FixedPoint;
		static const int	bits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &Obj);

#endif
