#ifndef C__CIRCLE_MUTANTSTACK_H
#define C__CIRCLE_MUTANTSTACK_H

#include <iostream>
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

template<typename T>
MutantStack<T>::MutantStack() {
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) {
    *this = other;
}

template<typename T>
MutantStack<T>::~MutantStack() {
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
    if (this == &other)
        return *this;
    std::stack<T>::operator=(other);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return std::stack<T>::c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return std::stack<T>::c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
    return std::stack<T>::c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
    return std::stack<T>::c.rend();
}

#endif //C__CIRCLE_MUTANTSTACK_H
