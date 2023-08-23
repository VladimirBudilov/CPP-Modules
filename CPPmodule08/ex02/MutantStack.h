#ifndef C__CIRCLE_MUTANTSTACK_H
#define C__CIRCLE_MUTANTSTACK_H

#include <iostream>
#include "vector"
#include "stack"
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack();
    MutantStack(const MutantStack<T> &other);
    ~MutantStack();

    MutantStack<T> &operator=(const MutantStack<T> &other);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;

};


#endif //C__CIRCLE_MUTANTSTACK_H
