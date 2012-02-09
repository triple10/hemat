#include "HComplex.h"
#include <iostream>
#include <stdexcept>
int main()
{
	try
	{	
		HComplex<double> t(3,5.2);
		std::cout << (t /= HComplex<double>(3, 1));
		return 0;
	}
	catch(std::domain_error my)
	{
		std::cerr << my.what() << std::endl;
	}
}
