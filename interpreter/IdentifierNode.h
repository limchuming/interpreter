#ifndef IDENTIFIER
#define IDENTIFIER

#include <memory>
#include <map>
#include <stdexcept>

class AnyType {
public:
	AnyType() :data_ptr(nullptr){}
	template <typename T> AnyType(const T &data_) :data_ptr(new InputType<T>(data_)) {}
	AnyType(const AnyType &other) :data_ptr(other.data_ptr->clone()) {}
	AnyType &operator=(AnyType &other) {
		AnyType(other).swap(*this);
		return *this;
	}
	void swap(AnyType& other) { other.data_ptr.swap(this->data_ptr); }
	template <typename T> T &get_data() { return dynamic_cast<InputType<T> &>(*data_ptr.get()).data; }
	template <typename T>	const T &get_data() const { return dynamic_cast<InputType<T> &>(*data_ptr.get()).data;}
  
private:
	struct Base {
		virtual ~Base() {}
		virtual Base *clone() const = 0;
	};

	template <typename T>
	struct InputType : Base {
		InputType(const T &data_) :data(data_) {}
		InputType(const InputType &newinput) :data(newinput.data) {}
		Base *clone() const { return new InputType<T>(*this); }
		T data;
	};

	std::unique_ptr<Base> data_ptr;
};

class IdentifierMap{
public:
  IdentifierMap(){}

  template <typename T>
  const T &get_identifier(const std::string &identifier_name) const{
      return idenmap.at(identifier_name).get_data<T>();
  }
  
  template <typename T>
  void set_identifier(const std::string &identifier_name, const T &variable){
    auto iden_search_iter = idenmap.find(identifier_name);
    if(iden_search_iter != idenmap.end()){
      AnyType tmp_var(variable);
      idenmap[identifier_name] = tmp_var;
    }else{
      idenmap.insert(std::pair<std::string,AnyType>(identifier_name,AnyType(variable)));
    }
  }  
  
private:  
  std::map<std::string,AnyType> idenmap;
};

#endif


