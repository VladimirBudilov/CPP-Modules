#ifndef C__CIRCLE_PMERGEME_HPP
#define C__CIRCLE_PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>


class PmergeMe {
private:
    static unsigned int _tail;
    static std::vector<unsigned int> _unsortedData;
    static std::vector<std::pair<unsigned int, unsigned int> > _pairs;
    static std::vector<unsigned int> _sortedData;
    static std::vector<unsigned int> _indexPendInsertSequence;
    static std::vector<unsigned int> _pendSequence;

    PmergeMe();
    PmergeMe(PmergeMe const &other);
    PmergeMe &operator=(PmergeMe const &other);
    ~PmergeMe();
    static void FindTail();
    static void SplitInPairs();
    static void SortDataInPairs();
    static void InsertionSort();
    static void AddBiggerNumbersToSortedData();
    static void PrintSortedData();
public:
    static std::vector<unsigned int> FJMI(std::vector<unsigned int> unsortedData);


    static void MergeSort();

    static void GetJacobsthalSequence();

    static void PrintJacobsthalSequence();

    static void PrintUnsortedData();

    static unsigned long GetJacobsthalNumberByIndex(int i);

    static void CreatePandSequence();
};


#endif //C__CIRCLE_PMERGEME_HPP
