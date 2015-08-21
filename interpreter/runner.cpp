#include <iostream>
#include <sstream>
#include <string>
#include "IdentifierNode.h"
#include "reader.h"

int main() {
	std::stringstream ss;
	//ss << "testiden = 2 + 5";
	IdentifierMap identifier_store;
	Reader reader(std::cin,identifier_store);
	reader.evaluate<int>();
	//identifier_store.set_identifier<int>("first_iden",5);
	//identifier_store.set_identifier<std::string>("second_iden","five_string");
	//std::cout << identifier_store.get_identifier<int>("first_iden") << std::endl;
	std::cout << identifier_store.get_identifier<int>("testiden") << std::endl;
	
  
	int stop;
	std::cin >> stop;

	return 0;
}