#include <iostream>
#include "IdentifierNode.h"

int main() {
  
  IdentifierMap identifier_store;
  identifier_store.set_identifier<int>("first_iden",5);
  identifier_store.set_identifier<std::string>("second_iden","five_string");


  std::cout << identifier_store.get_identifier<int>("first_iden") << std::endl;
  std::cout << identifier_store.get_identifier<std::string>("second_iden") << std::endl;
  
  
	int stop;
	std::cin >> stop;

	return 0;
}