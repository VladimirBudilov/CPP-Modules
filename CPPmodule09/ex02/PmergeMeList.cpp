#include "PmergeMeList.hpp"

void PmergeMeList::FJMI(std::list<int> &unsortedData) {
    _dataList = unsortedData;
    Validation();
    MergeSort(_dataList, _dataList.size());
    unsortedData = _dataList;
}

///Validation
void PmergeMeList::Validation() {
    if (_dataList.size() == 1) {
        std::cout << "Only one element" << std::endl;
        exit(1);
    }
    if (IsSorted(_dataList)) {
        std::cout << "Data is sorted" << std::endl;
        exit(1);
    }
    if (HasDuplicates(_dataList)) {
        std::cout << "Data has duplicates" << std::endl;
        exit(1);
    }
}

bool PmergeMeList::IsSorted(std::list<int> &list) {

    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator nextIt = list.begin();
    ++nextIt;
    for (; it != list.end(); ++nextIt, ++it) {
        if (*it > *(nextIt))
            return false;
    }
    return true;
}

bool PmergeMeList::HasDuplicates(std::list<int> list) {
    std::list<int> uniquelist;
    std::list<int>::iterator it = list.begin();
    for (; it != list.end(); it++) {
        if (std::find(uniquelist.begin(), uniquelist.end(), *it) != uniquelist.end())
            return true;
        uniquelist.push_front(*it);
    }
    return false;
}

///Sort algorithm
void PmergeMeList::MergeSort(std::list<int> &list, int inputSize) {

    ///here simple
    if (inputSize == 0 || inputSize == 1)
        return;
    int tail = FindTail(inputSize, list);
    int size = inputSize / 2;
    std::list<std::pair<int, int> > pairs = SplitInPairs(inputSize, list);
    std::list<int> mainNumbers = GetMainNumbers(size, pairs);
    std::list<int> pandNumbers = CreatePandSequence(size, pairs);
    MergeSort(mainNumbers, size);

    ///here magic
    //add first pand
    list.clear();
    //add main numbers
    std::list<int>::iterator mainNumbersIt = mainNumbers.begin();
    for (; mainNumbersIt != mainNumbers.end(); ++mainNumbersIt) {
        list.insert(list.end(), *mainNumbersIt);
    }
    list.insert(list.begin(), FindPandByMainNumber(mainNumbers.front(), pairs));

    int scopeEnd = 1;
    int scopeStart;
    int scopeSize = 0;
    //offset from the start of vector
    int offset = 0;
    while (offset < size - 1) {
        //find new scope and his size
        scopeEnd *= 2;
        scopeStart = scopeSize;
        scopeSize = scopeEnd - scopeStart;
        //use if size of vector less than max number in scope.
        int shiftInCurrentScope = (size - 1) - (offset + scopeSize);
        //if size bigger max number in scope, you don't use shift
        shiftInCurrentScope = shiftInCurrentScope > 0 ? 0 : shiftInCurrentScope;
        //go through groupSize and check
        for (int i = 0; i < scopeSize && (offset + i < size - 1); i++) {
            int indexForInsert = offset + scopeSize - i + shiftInCurrentScope;
            std::list<int>::iterator it = mainNumbers.begin();
            std::advance(it, indexForInsert);
            int pandToInsert = FindPandByMainNumber(*it, pairs);
            int sizeOfScopeToInsert = 1 + size + offset + i;
            InsertByBinarySearch(pandToInsert, sizeOfScopeToInsert, list);
        }
        offset += scopeSize;
    }
    if (tail > 0) {
        int index = BinariSearch(list, size * 2, tail);
        std::list<int>::iterator it = list.begin();
        std::advance(it, index);
        list.insert(it, tail);
    }
}

int PmergeMeList::FindTail(int size, std::list<int> &list) {
    if (size % 2 == 0) {
        return 0;
    } else {
        int temp = list.back();
        list.erase(--list.end());
        return temp;
    }
}

std::list<std::pair<int, int> > PmergeMeList::SplitInPairs(int size, std::list<int> &unsortedlist) {
    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = unsortedlist.begin();
    std::list<int>::iterator nextIt = unsortedlist.begin();
    std::list<int>::iterator endIt = unsortedlist.begin();
    std::advance(endIt, size);

    ++nextIt;
    for (; nextIt != endIt; std::advance(it, 2), std::advance(nextIt, 2)) {
        if (*it > *nextIt)
            pairs.push_back(std::make_pair(*it, *nextIt));
        else
            pairs.push_back(std::make_pair(*nextIt, *it));
    }
    return pairs;
}

std::list<int> PmergeMeList::GetMainNumbers(int size, std::list<std::pair<int, int> > &pairs) {
    std::list<int> mainNumbers;
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    std::list<std::pair<int, int> >::iterator endit = pairs.begin();
    std::advance(endit, size);
    for (; it != endit; ++it) {
        mainNumbers.push_back(it->first);
    }
    return mainNumbers;
}

std::list<int> PmergeMeList::CreatePandSequence(int size, std::list<std::pair<int, int> > &pairs) {
    std::list<int> pand;
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    std::list<std::pair<int, int> >::iterator endIt = pairs.begin();
    std::advance(endIt, size);
    for (; it != endIt; it++) {
        pand.push_back(it->second);
    }
    return pand;
}

int PmergeMeList::FindPandByMainNumber(int mainNumber, std::list<std::pair<int, int> > pairs) {
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    for (; it != pairs.end(); ++it) {
        if (mainNumber == it->first)
            return it->second;
    }
    std::cout << "error" << std::endl;
    return 0;
}


///Binary search
void PmergeMeList::InsertByBinarySearch(int pand, int size, std::list<int> &list) {
    int index = BinariSearch(list, size, pand);
    std::list<int>::iterator it = list.begin();
    std::advance(it, index);
    list.insert(it, pand);
}

int PmergeMeList::BinariSearch(std::list<int> &list, int size, int pand) {
    int left = 0;
    int right = size - 1;
    int middle = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        std::list<int>::iterator it = list.begin();
        std::advance(it, middle);
        if (pand < *it) {
            right = middle - 1;
        } else if (pand > *it) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return left;
}

PmergeMeList::PmergeMeList() {

}

PmergeMeList::~PmergeMeList() {

}

PmergeMeList::PmergeMeList(const PmergeMeList &copy) {
    *this = copy;
}

PmergeMeList &PmergeMeList::operator=(const PmergeMeList &copy) {
    if (this != &copy) {
        PmergeMe::_dataList = copy._dataList;
    }
    return *this;
}
