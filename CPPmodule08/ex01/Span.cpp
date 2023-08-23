#include "Span.h"
Span::Span()
{
	_N = 0;
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::Span(unsigned int N)
{
	_N = N;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_N = other._N;
	_arr = other._arr;
	return *this;
}

void Span::addNumber(int n)
{
	if (_arr.size() >= _N)
		throw std::out_of_range("Span is full");
	_arr.push_back(n);
}


