#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;

	Fixed fixed1(3);
    	Fixed fixed2(2);
	Fixed fixed3(fixed2);
	

	std::cout << fixed1 << " * " << fixed2 <<  " = " << fixed2 * fixed1 << std::endl;
	std::cout << fixed1 << " + " << fixed2 <<  " = " << fixed2 + fixed1 << std::endl;
	std::cout << fixed1 << " - " << fixed2 <<  " = " << fixed2 - fixed1 << std::endl;
	std::cout << fixed1 << " / " << fixed2 <<  " = " << fixed2 / fixed1 << std::endl;
	std::cout << b << std::endl;
	std::cout << std::boolalpha; // muda o retorno das de baixo
    	std::cout << (fixed3 == fixed2) << std::endl;
   	std::cout << (fixed1 == fixed2) << std::endl;
	std::cout << (fixed1  > fixed2) << std::endl;
	std::cout << (fixed1  < fixed2) << std::endl;
	std::cout << (fixed1 >= fixed2) << std::endl;
	std::cout << (fixed1 <= fixed2) << std::endl;
	std::cout << (fixed1 != fixed2) << std::endl;
	return 0;
}
