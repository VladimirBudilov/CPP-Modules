#include "PmergeMe.hpp"
#include "PmergeMeVector.hpp"
#include "PmergeMeList.hpp"

void PmergeMe::FJMI(std::vector<int> &unsortedData, int containerType) {
    if (containerType == VECTOR) {
        PmergeMeVector pmergeMeVector;
        pmergeMeVector.FJMI(unsortedData);
    } else {
        std::cout << "Wrong container type" << std::endl;
        exit(1);
    }
}

void PmergeMe::SetContainerType(int type) {
    _containerType = type;
}

void PmergeMe::FJMI(std::list<int> &unsortedData, int containerType) {
    if (containerType == LIST) {
        PmergeMeList pmergeMeList;
        pmergeMeList.FJMI(unsortedData);
    } else {
        std::cout << "Wrong container type" << std::endl;
        exit(1);
    }
}

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy) {
        _containerType = copy._containerType;
        _dataVector = copy._dataVector;
        _dataList = copy._dataList;
    }
    return *this;
}

PmergeMe::~PmergeMe() {

}
