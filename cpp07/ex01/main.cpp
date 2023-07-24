#include "iter.hpp"

template <typename T, size_t N>
size_t arraySize(T (&)[N])
{
	return N;
}

template <typename T>
void duplicate(T &num)
{
	num *= 2;
}

template <typename T>
void modifyString(T &str)
{
	str = "Hello, " + str;
}

template <typename T>
void print(T &values)
{
	std::cout << std::fixed << std::setprecision(2) << values <<  " / ";
}

void testArrayInt(void)
{
	std::cout << "\n---- Testing int array ----\n";
	int intArray[] = {1, 2, 3, 4, 5};
	size_t length = arraySize(intArray);
	iter(intArray, length, print<int>);
	std::cout << std::endl;
	iter(intArray, length, duplicate<int>);
	iter(intArray, length, print<int>);
	std::cout << std::endl;
}

void testArrayFloat(void)
{
	std::cout << "\n---- Testing float array ----\n";
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t length = arraySize(floatArray);
	iter(floatArray, length, print<float>);
	std::cout << std::endl;
	iter(floatArray, length, duplicate<float>);
	iter(floatArray, length, print<float>);
	std::cout << std::endl;
}

void testArrayDouble(void)
{
	std::cout << "\n---- Testing double array ----\n";
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t length = arraySize(doubleArray);
	iter(doubleArray, length, print<double>);
	std::cout << std::endl;
	iter(doubleArray, length, duplicate<double>);
	iter(doubleArray, length, print<double>);
	std::cout << std::endl;
}

void testArrayString(void)
{
	std::cout << "\n---- Testing string array ----\n";
	std::string stringArray[] = {"World", "42", "meritissimo1"};
	size_t length = arraySize(stringArray);
	iter(stringArray, length, print<std::string>);
	std::cout << std::endl;
	iter(stringArray, length, modifyString<std::string>);
	std::cout << std::endl;
	iter(stringArray, length, print<std::string>);
	std::cout << std::endl;
}

int main( void )
{
	testArrayInt();
	testArrayFloat();
	testArrayDouble();
	testArrayString();
	return (0);
}