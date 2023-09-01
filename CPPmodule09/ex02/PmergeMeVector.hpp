#ifndef C__CIRCLE_PMERGEMEVECTOR_HPP
#define C__CIRCLE_PMERGEMEVECTOR_HPP

#include "PmergeMe.hpp"

class PmergeMeVector : public PmergeMe {
private:
    void Validation();
    bool HasDuplicates(std::vector<int> vector);
    bool IsSorted(std::vector<int> &vector);

    void MergeSort(std::vector<int> &vector, int inputSize);

    int FindTail(int size, std::vector<int> &vector);
    std::vector<std::pair<int, int> > SplitInPairs(int size, std::vector<int> &unsortedVector);
    std::vector<int> GetMainNumbers(int size, std::vector<std::pair<int, int> > &pairs);
    std::vector<int> CreatePandSequence(int size, std::vector<std::pair<int, int> > &pairs);
    int FindPandByMainNumber(int mainNumber, std::vector<std::pair<int, int> > pairs);

    void InsertByBinarySearch(int pand, int size, std::vector<int> &vector);
    int BinariSearch(std::vector<int> &vector, int size, int pand);

public:
    PmergeMeVector();
    ~PmergeMeVector();
    PmergeMeVector(const PmergeMeVector &copy);
    PmergeMeVector &operator=(const PmergeMeVector &copy);
    void FJMI(std::vector<int> &unsortedData);
};


#endif //C__CIRCLE_PMERGEMEVECTOR_HPP
