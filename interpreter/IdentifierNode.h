#ifndef IDENTIFIER
#define IDENTIFIER

#include <memory>

class AnyType {
public:
	void swap(AnyType& other) { other.data_ptr.swap(this->data_ptr); }

	AnyType() :data_ptr(nullptr){}
	template <typename T> AnyType(const T &data_) :data_ptr(new InputType<T>(data_)) {}
	AnyType(const AnyType &other) :data_ptr(other.data_ptr->clone()) {}
	AnyType &operator=(AnyType &other) {
		AnyType(other).swap(*this);
		return *this;
	}
	template <typename T>	T &get_data() { return (dynamic_cast<InputType<T> &>(*(data_ptr.get()))).data; }
	template <typename T>	const T &get_data() const { return (dynamic_cast<InputType<T> &>(*(data_ptr.get()))).data; }

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

#endif

