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
    if(_N == 0)
        throw std::out_of_range("Span is empty");
	if (_arr.size() >= _N)
		throw std::out_of_range("Span is full");
	_arr.push_back(n);
}

int Span::shortestSpan()
{
    if(_N == 0)
        throw std::out_of_range("Span is empty");
	if (_arr.size() <= 1)
		throw std::out_of_range("Span is empty or has only one element");
	std::vector<int> tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
    if(_N == 0)
        throw std::out_of_range("Span is empty");
	if (_arr.size() <= 1)
		throw std::out_of_range("Span is empty or has only one element");
	std::vector<int> tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

Span::~Span()
{

}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_arr.size() + std::distance(begin, end) > _N)
		throw std::out_of_range("Span is full");
	_arr.insert(_arr.end(), begin, end);
}


