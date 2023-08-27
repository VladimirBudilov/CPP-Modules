#include "PmergeMe.hpp"
std::vector<unsigned int> PmergeMe::_unsortedData;
std::vector<std::pair<unsigned int, unsigned int> > PmergeMe::_pairs;
std::vector<unsigned int> PmergeMe::_sortedData;
std::vector<unsigned int> PmergeMe::_indexPendInsertSequence;
std::vector<unsigned int> PmergeMe::_pendSequence;

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
    std::cout << "Sorted data: ";
    for(int i = 0; i < _sortedData.size(); i++) {
        std::cout << _sortedData[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::MergeSort() {
    CreatePandSequence();
    GetJacobsthalSequence();

}

void PmergeMe::GetJacobsthalSequence() {
    bool isLastAddedWasJacobsthal = false;
    std::vector<unsigned int> jecobsthalSequence;
    if(_sortedData.size() == 1) {
        return;
    }
    for(int i = 3; GetJacobsthalNumberByIndex(i) < _pendSequence.size() - 1; i++) {
        jecobsthalSequence.push_back(GetJacobsthalNumberByIndex(i));
    }
    _indexPendInsertSequence.push_back(1);
    for(int i = 1; i < _pendSequence.size() ; i++) {
        if(jecobsthalSequence.size() != 0 && isLastAddedWasJacobsthal == false){
            _indexPendInsertSequence.push_back(jecobsthalSequence[0]);
            jecobsthalSequence.erase(jecobsthalSequence.begin());
            isLastAddedWasJacobsthal = true;
        }
        for (std::vector<unsigned int>::iterator iit = _indexPendInsertSequence.begin() ; iit != _indexPendInsertSequence.end(); iit++ ){
            if ( *iit == i )
                i++;
        }
        _indexPendInsertSequence.push_back( i );
        isLastAddedWasJacobsthal = false;
    }
}

void PmergeMe::PrintJacobsthalSequence() {
    std::cout << "Jacobsthal sequence: ";
    for(int i = 0; i < _indexPendInsertSequence.size(); i++) {
        std::cout << _indexPendInsertSequence[i] << " ";
    }
    std::cout << std::endl;

}

void PmergeMe::PrintUnsortedData() {
    std::cout << "Unsorted data: ";
    for(int i = 0; i < _pendSequence.size(); i++) {
        std::cout << _pendSequence[i] << " ";
    }
    std::cout << std::endl;

}

unsigned long PmergeMe::GetJacobsthalNumberByIndex(int i) {
    if(i == 0) {
        return 0;
    }
    if(i == 1) {
        return 1;
    }
    return GetJacobsthalNumberByIndex(i - 1) + 2 * GetJacobsthalNumberByIndex(i - 2);
}

void PmergeMe::CreatePandSequence() {
for(int i = 1; i < _pairs.size(); i++) {
    _pendSequence.push_back(_pairs[i].second);
    }
}
