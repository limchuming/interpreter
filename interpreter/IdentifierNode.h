#ifndef IDENTIFIER
#define IDENTIFIER

#include <map>
#include <string>
#include <memory>

class Identifier {
public:
	Identifier(const std::string &name_) {}
	virtual ~Identifier() = 0;
};

template<class T>
class IdentifierTyped : public Identifier {
public:
	IdentifierTyped(const T &value_);
	void set_value(const T&);
	T get_value();
private:
	T value;
};




class IdentifierList {
public:
	auto get_identifier_value(const std::string &);
private:
	std::map<std::string, std::unique_ptr<Identifier>> identifier_map;
}
#endif

 