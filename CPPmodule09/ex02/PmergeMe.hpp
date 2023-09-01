#ifndef C__CIRCLE_PMERGEME_HPP
#define C__CIRCLE_PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include "Tools.hpp"

class PmergeMe {
protected:
    int _containerType;
    std::vector<int> _dataVector;
    std::list<int> _dataList;

    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
public:
    virtual ~PmergeMe();
    void SetContainerType(int type);
    static void FJMI(std::vector<int> &unsortedData, int containerType);
    static void FJMI(std::list<int> &unsortedData, int containerType);
};

#endif //C__CIRCLE_PMERGEME_HPP
