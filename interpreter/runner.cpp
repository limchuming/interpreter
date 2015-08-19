#include <iostream>
#include <string>

using std::cin;
char ch;

double factor() {
	double var, minus = 1.0;
	static char id[200];
	cin >> ch;
	
	while (ch == '+' || ch == '-') {
		if (ch == '-') {
			minus += -1.0;
		}
		cin >> ch;
	}

	std::cout << ch << std::endl;

	if (isdigit(ch) || ch == '.') {
		cin.putback(ch);
		cin >> var >> ch;
		std::cout << "popo" << std::endl;
	}
	else if (ch == '(') {
		var = 2.9;
		if (ch == ')') {
			cin >> ch;
		}
		else {
			throw("here");
		}
	}
	else {
		var = 3.9;
	}

	std::cout << "here B" << std::endl;
	return minus*var;
}

void readId(char *id) {
	int i = 0;
	std::cout << ch << std::endl;
	if (isspace(ch)) {
		cin >> ch;
		std::cout << "asdd" << std::endl;
	}
	if (isalpha(ch)) {
		while (isalnum(ch)) {
			id[i++] = ch;
			cin.get(ch);
		}
		id[i] = '\0';
	}
	else {
		throw("identifier expected");
	}
	
}


int main() {
	
	cin.get(ch);
	std::cout << ch << std::endl;
	cin.get(ch);
	std::cout << ch << std::endl;
	/*
	char teststring[20];
	readId(teststring);
	printf("%s\n",teststring);
	*/

	



	int stop;
	cin >> stop;

	return 0;
}