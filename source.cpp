#include "stdafx.h"
#include "Stringi.h"
void main()
{
	Stringi a("sdqcg");
	std::cout << a[1] << std::endl;
	std::cout << a('c') << std::endl;
	int len = a;
	std::cout << len << std::endl;
}