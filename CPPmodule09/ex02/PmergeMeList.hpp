#ifndef C__CIRCLE_PMERGEMELIST_HPP
#define C__CIRCLE_PMERGEMELIST_HPP

#include "PmergeMe.hpp"

class PmergeMeList : public PmergeMe{
private:
    void Validation();
    bool HasDuplicates(std::list<int> list);
    bool IsSorted(std::list<int> &list);

    void MergeSort(std::list<int> &list, int inputSize);

    int FindTail(int size, std::list<int> &list);
    std::list<std::pair<int, int> > SplitInPairs(int size, std::list<int> &unsortedlist);
    std::list<int> GetMainNumbers(int size, std::list<std::pair<int, int> > &pairs);
    std::list<int> CreatePandSequence(int size, std::list<std::pair<int, int> > &pairs);
    int FindPandByMainNumber(int mainNumber, std::list<std::pair<int, int> > pairs);

    void InsertByBinarySearch(int pand, int size, std::list<int> &list);
    int BinariSearch(std::list<int> &list, int size, int pand);

public:
    PmergeMeList();
    ~PmergeMeList();
    PmergeMeList(const PmergeMeList &copy);
    PmergeMeList &operator=(const PmergeMeList &copy);

    void FJMI(std::list<int> &unsortedData);
};


#endif //C__CIRCLE_PMERGEMELIST_HPP
