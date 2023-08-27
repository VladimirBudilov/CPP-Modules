#include "PmergeMe.hpp"
std::vector<unsigned int> PmergeMe::_unsortedData;
std::vector<std::pair<unsigned int, unsigned int> > PmergeMe::_pairs;
std::vector<unsigned int> PmergeMe::_sortedData;
std::vector<unsigned int> PmergeMe::_jacobsthalSequence;

unsigned int PmergeMe::_tail = 0;



void PmergeMe::FindTail() {
    if(_unsortedData.size() % 2 == 0) {
        _tail = 0;
    }
    else {
        _tail = _unsortedData.back();
        _unsortedData.pop_back();
    }
}

std::vector<unsigned int> PmergeMe::FJMI(std::vector<unsigned int> unsortedData) {
    _unsortedData = unsortedData;
    FindTail();
    SplitInPairs();
    SortDataInPairs();
    InsertionSort();
    AddBiggerNumbersToSortedData();
    MergeSort();
    PrintSortedData();
    PrintUnsortedData();
    PrintJacobsthalSequence();
    return _sortedData;
}

void PmergeMe::SplitInPairs() {
    for (int i = 0; i < _unsortedData.size(); i += 2) {
       _pairs.push_back(std::make_pair(_unsortedData[i], _unsortedData[i + 1]));
    }
}

void PmergeMe::SortDataInPairs() {
    for(int i = 0; i < _pairs.size(); i++) {
        if(_pairs[i].first < _pairs[i].second) {
            std::swap(_pairs[i].first, _pairs[i].second);
        }
    }
}

void PmergeMe::InsertionSort() {
    // 5 4 3 2 1
    for(int i = 1; i < _pairs.size(); i++) {
        int j = i;
        while(j > 0 && _pairs[j - 1].first > _pairs[j].first) {
            std::swap(_pairs[j - 1], _pairs[j]);
            j--;
        }
    }
}

void PmergeMe::AddBiggerNumbersToSortedData() {
    _sortedData.push_back(_pairs[0].second);
    for(int i = 0; i < _pairs.size(); i++) {
        _sortedData.push_back(_pairs[i].first);
    }
}

void PmergeMe::PrintSortedData() {
    for(int i = 0; i < _sortedData.size(); i++) {
        std::cout << _sortedData[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::MergeSort() {
    GetJacobsthalSequence();

}

void PmergeMe::GetJacobsthalSequence() {
    _jacobsthalSequence.push_back(0);
    _jacobsthalSequence.push_back(1);
    for(int i = 2; i < _sortedData.size(); i++) {
        _jacobsthalSequence.push_back(_jacobsthalSequence[i - 1] + 2 * _jacobsthalSequence[i - 2]);
    }
}

void PmergeMe::PrintJacobsthalSequence() {
    for(int i = 0; i < _jacobsthalSequence.size(); i++) {
        std::cout << _jacobsthalSequence[i] << " ";
    }
    std::cout << std::endl;

}

void PmergeMe::PrintUnsortedData() {
    for(int i = 0; i < _pairs.size(); i++) {
        std::cout << _pairs[i].second << " ";
    }
    std::cout << std::endl;

}
