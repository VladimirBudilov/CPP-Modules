#ifndef C__CIRCLE_ARRAY_H
#define C__CIRCLE_ARRAY_H

#include "iostream"

template<typename T>
class Array {
private:
	T *_arr;
	size_t _len;
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	~Array();
	Array &operator=(Array const &other);
	T &operator[](size_t index);
	const T &operator[](size_t index) const;
	size_t size() const;
};

template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= _len)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template<typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= _len)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_arr = new T[n];
	_len = n;
	for (size_t i = 0; i < _len; i++)
		_arr[i] = T();
}

template<typename T>
Array<T>::Array()
{
	_arr = new T[0];
	_len = 0;
}

template<typename T>
Array<T>::Array(Array const &other)
{
	_len = other._len;
	_arr = new T[_len];
	for (size_t i = 0; i < _len; i++)
		_arr[i] = other._arr[i];
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other) {
		delete[] _arr;
		_len = other._len;
		_arr = new T[_len];
		for (size_t i = 0; i < _len; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template<typename T>
size_t Array<T>::size() const
{
	return _len;
}

#endif //C__CIRCLE_ARRAY_H
