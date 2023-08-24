#ifndef C__CIRCLE_SPAN_H
#define C__CIRCLE_SPAN_H

#include <iostream>
#include <vector>

class Span {
	private:
	unsigned int _N;
	std::vector<int> _arr;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &other);
	~Span();
	Span &operator=(Span const &other);
	void addNumber(int n);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
};


#endif //C__CIRCLE_SPAN_H
