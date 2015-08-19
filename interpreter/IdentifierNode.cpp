#include "IdentifierNode.h"

template <class T>
IdentifierTyped<T>::IdentifierTyped(const T &value_) :value(value_) {}

template <class T>
void IdentifierTyped<T>::set_value(const T &value_) {
	value = value_;
}

template <class T>
T IdentifierTyped<T>::get_value() {
	return value;
}

