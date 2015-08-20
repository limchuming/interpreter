#ifndef READER
#define READER

#include "IdentifierNode.h"
#include <algorithm>
#include <iostream>
#include <sstream>

class Reader{
public:
	Reader(std::istream &is_, IdentifierMap &id_map);
	std::string read_identifier();
	template <typename T> T factor();
	template <typename T> T term();
	template <typename T> T expression();
	template <typename T> T evaluate();
private:
	const std::string allowed_idenchar;
	char current_ch;
	std::istream &is;
	IdentifierMap &identifier_map;
};	

Reader::Reader(std::istream &is_, IdentifierMap &id_map)
	:allowed_idenchar("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_")
	,is(is_), identifier_map(id_map){}

std::string Reader::read_identifier(){
	if(isspace(current_ch)){
		// skip empty spaces
		is >> current_ch;
	}
	if(isalpha(current_ch)){
		// first letter has to be a letter of the alphabet
		// thereafter it needs to be in the allowed_idenchar list
		std::string new_iden_name;
		new_iden_name.push_back(current_ch);    
		current_ch = is.get();

		while (std::any_of(allowed_idenchar.cbegin(), allowed_idenchar.cend(), [this](char idch) {return current_ch == idch; })) {
			// get letter by letter and stop when the char stops being in allowed_idenchar
			new_iden_name.push_back(current_ch);
			current_ch = is.get();
		}
		if (isspace(current_ch)) {
			is >> current_ch; // skip empty spaces
		}
		return new_iden_name;
		}
	else {
		throw std::logic_error("Not an identifier.");
	}
}

template <typename T>
T Reader::expression(){
	T retval = term<T>();
	while (current_idenchar == '+' || current_idenchar == '-' ) {
		if (current_idenchar == '+') {
			retval = retval + term<T>();
		}
		else {
			retval = retval - term<T>();
		}
	}
	return retval;
}

template <typename T>
T Reader::term() {
	T retval = factor<T>();
	while (true) {
		switch (current_idenchar) {
		case '*': retval = retval * factor<T>(); break;
		case '/': retval = retval / factor<T>(); break;
		default: return retval;
		}
	}
}

template <typename T>
T Reader::factor() {
	T retval; 
	bool negative = false;
	double float_number;
	is >> current_idenchar;

	while (current_idenchar == '-' || current_idenchar == '+') {
		if (current_idenchar == '-') {
			negative = negative ? false : true;
		}
		is >> current_idenchar;
	}

	if (isdigit(current_iden) || current_iden == '.') {
		is.putback(current_iden);
		is >> float_number >> current_idenchar;
	}
	else if (current_iden == '(') {
		retval = expression<T>();
		if (current_iden == ')') {
			is >> current_iden;
		}
		else {
			throw std::logic_error("Open bracket is not closed");
		}
	}
	else {
		std::string new_identifier = read_identifier();
		try{
			retval = identifier_map.get_identifier<T>(new_identifier);
		}
		catch (const std::bad_cast &ex) {
			// do something
		}
		catch (const std::out_of_range &ex) {
			// do something
		}
	}
	
	return negative ? -retval : retval;
}

template <typename T> 
T evaluate() {

}

#endif


