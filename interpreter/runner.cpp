#include <iostream>
#include "IdentifierNode.h"

int main() {

	AnyType test(4);
	AnyType newobj;
	newobj = test;
	newobj.get_data<int>() = 99;
	std::cout << test.get_data<int>() <<std::endl;
	std::cout << newobj.get_data<int>() << std::endl;

	
	int stop;
	std::cin >> stop;

	return 0;
}