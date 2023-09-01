#include "PmergeMeVector.hpp"
#include "PmergeMe.hpp"

void PmergeMeVector::FJMI(std::vector<int> &unsortedData) {
    _dataVector = unsortedData;
    Validation();
    MergeSort(_dataVector, _dataVector.size());
    std::vector<int> sortedVector = _dataVector;
    unsortedData = sortedVector;
}

///Validation
void PmergeMeVector::Validation() {
    if (_dataVector.size() == 1) {
        std::cout << "Only one element" << std::endl;
        exit(1);
    }
    if (IsSorted(_dataVector)) {
        std::cout << "Data is sorted" << std::endl;
        exit(1);
    }
    if (HasDuplicates(_dataVector)) {
        std::cout << "Data has duplicates" << std::endl;
        exit(1);
    }
}

bool PmergeMeVector::IsSorted(std::vector<int> &vector) {
    for (int i = 0; i < static_cast<int>(vector.size()); i++) {
        if (vector[i] > vector[i + 1])
            return false;
    }
    return true;
}

bool PmergeMeVector::HasDuplicates(std::vector<int> vector) {
    std::vector<int> uniqueVector;
    for (int i = 0; i < static_cast<int>(vector.size()); i++) {
        if (std::find(uniqueVector.begin(), uniqueVector.end(), vector[i]) != uniqueVector.end())
            return true;
        uniqueVector.push_back(vector[i]);
    }
    return false;
}


///Sort algorithm
void PmergeMeVector::MergeSort(std::vector<int> &vector, int inputSize) {

    ///here simple
    if (inputSize == 0 || inputSize == 1)
        return;
    int tail = FindTail(inputSize, vector);
    int size = inputSize / 2;
    std::vector<std::pair<int, int> > pairs = SplitInPairs(inputSize, vector);
    std::vector<int> mainNumbers = GetMainNumbers(size, pairs);
    std::vector<int> pandNumbers = CreatePandSequence(size, pairs);
    MergeSort(mainNumbers, size);

    ///here magic
    //add first pand
    vector.clear();
    vector.insert(vector.begin(), FindPandByMainNumber(mainNumbers[0], pairs));
    //add main numbers
    for (int i = 1, j = 0; j < static_cast<int>(mainNumbers.size()); i++, j++) {
        vector.insert(vector.begin() + i, mainNumbers[j]);
    }

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
            int pandToInsert = FindPandByMainNumber(mainNumbers[indexForInsert], pairs);
            int sizeOfScopeToInsert = 1 + size + offset + i;
            InsertByBinarySearch(pandToInsert, sizeOfScopeToInsert, vector);
        }
        offset += scopeSize;
    }
    if (tail > 0) {
        int index = BinariSearch(vector, size * 2, tail);
        vector.insert(vector.begin() += index, tail);
    }
}

int PmergeMeVector::FindTail(int size, std::vector<int> &vector) {
    if (size % 2 == 0) {
        return 0;
    } else {
        int temp = vector[size - 1];
        vector.erase(--vector.end());
        return temp;
    }
}

std::vector<std::pair<int, int> > PmergeMeVector::SplitInPairs(int size, std::vector<int> &unsortedVector) {
    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < size; i += 2) {
        if (unsortedVector[i] > unsortedVector[i + 1])
            pairs.push_back(std::make_pair(unsortedVector[i], unsortedVector[i + 1]));
        else
            pairs.push_back(std::make_pair(unsortedVector[i + 1], unsortedVector[i]));
    }
    return pairs;
}

std::vector<int> PmergeMeVector::GetMainNumbers(int size, std::vector<std::pair<int, int> > &pairs) {
    std::vector<int> mainNumbers;
    for (int i = 0; i < size; i++) {
        mainNumbers.push_back(pairs[i].first);
    }
    return mainNumbers;
}

std::vector<int> PmergeMeVector::CreatePandSequence(int size, std::vector<std::pair<int, int> > &pairs) {
    std::vector<int> pand;
    for (int i = 0; i < size; i++) {
        pand.push_back(pairs[i].second);
    }
    return pand;
}

int PmergeMeVector::FindPandByMainNumber(int mainNumber, std::vector<std::pair<int, int> > pairs) {
    for (int i = 0; i < static_cast<int>(pairs.size()); i++) {
        if (mainNumber == pairs[i].first)
            return pairs[i].second;
    }
    std::cout << "error" << std::endl;
    return 0;
}


///Binary search
void PmergeMeVector::InsertByBinarySearch(int pand, int size, std::vector<int> &vector) {
    int index = BinariSearch(vector, size, pand);
    vector.insert(vector.begin() + index, pand);
}

int PmergeMeVector::BinariSearch(std::vector<int> &vector, int size, int pand) {
    int left = 0;
    int right = size - 1;
    int middle = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        if (pand < vector[middle]) {
            right = middle - 1;
        } else if (pand > vector[middle]) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return left;
}


//ortodox staff

PmergeMeVector::PmergeMeVector() {}

PmergeMeVector::~PmergeMeVector() {}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &copy) { _dataVector = copy._dataVector; }

PmergeMeVector &PmergeMeVector::operator=(const PmergeMeVector &copy) {
    _dataVector = copy._dataVector;
    return *this;
}
