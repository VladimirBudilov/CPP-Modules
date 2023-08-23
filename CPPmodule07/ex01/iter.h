#ifndef C__CIRCLE_ITER_H
#define C__CIRCLE_ITER_H

#include "iostream"

template <typename T>
void print(T &i) {
	std::cout << i << std::endl;
}

template <typename T>
void iter(T *arr, size_t len, void (*f)(T&)) {
	for (size_t i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T, typename G>
void iter(T *arr, size_t len,  void (*f)(G&)) {
	for (size_t i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T>
void increment(T &i) {
	i++;
}


#endif //C__CIRCLE_ITER_H
