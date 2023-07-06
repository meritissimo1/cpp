#include "Fixed.hpp"

int main( void )
{

	std::cout << "PDF tests\n";
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n\nMy tests\n";
	Fixed fixed0(2);
	Fixed fixed1(3);
    Fixed fixed2(2);	
	Fixed fixed3(fixed2);
	Fixed fixed4(4);
	const Fixed fixed5(5);
	const Fixed fixed6(6);

	std::cout << fixed2 << " * " << fixed1 <<  " = " << fixed2 * fixed1 << std::endl;
	std::cout << fixed2 << " + " << fixed1 <<  " = " << fixed2 + fixed1 << std::endl;
	std::cout << fixed2 << " - " << fixed1 <<  " = " << fixed2 - fixed1 << std::endl;
	std::cout << fixed2 << " / " << fixed1 <<  " = " << fixed2 / fixed1 << std::endl;
	
	std::cout << std::endl;
	std::cout << "The biggest between "  << fixed1 << " and " << fixed4	 << " is: " << fixed1.max(fixed1, fixed4) << std::endl;
	std::cout << "The biggest between "  << fixed5 << " and " << fixed6	 << " is: " << fixed1.max(fixed5, fixed6) << std::endl;
	std::cout << "The smallest between " << fixed5 << " and " << fixed6	 << " is: " << fixed1.min(fixed5, fixed6) << std::endl;
	std::cout << "The smallest between " << fixed5 << " and " << fixed6	 << " is: " << fixed1.min(fixed5, fixed6) << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha; // muda o retorno dos std::cout abaixo para um valor bool
   
   	std::cout << fixed3 << " == " << fixed2 << " = " << (fixed3 == fixed2) << std::endl;
   	std::cout << fixed1 << " == " << fixed2 << " = " << (fixed1 == fixed2) << std	::endl;
	std::cout << fixed1 << " > "  << fixed2 << " = " << (fixed1  > fixed2) << std::endl;
	std::cout << fixed1 << " < "  << fixed2 << " = " << (fixed1  < fixed2) << std::endl;
	std::cout << fixed1 << " >= " << fixed2 << " = " << (fixed1 >= fixed2) << std::endl;
	std::cout << fixed1 << " <= " << fixed2 << " = " << (fixed1 <= fixed2) << std::endl;		
	std::cout << fixed0 << " <= " << fixed2 << " = " << (fixed0 <= fixed2) << std::endl;
	std::cout << fixed0 << " >= " << fixed2 << " = " << (fixed0 >= fixed2) << std::endl;
	std::cout << fixed1 << " != " << fixed2 << " = " << (fixed1 != fixed2) << std::endl;

	return 0;
}
