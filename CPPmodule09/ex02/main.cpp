#include "PmergeMe.hpp"

int main( void ) {

    int vectorSize = 21;
    std::vector<unsigned int> test;
    test.reserve(vectorSize);
for (int i = 0; i < vectorSize; i++) {
    //fill the vector with random numbers
    test.push_back(rand() % 100);
    }
    //Print unsorted data
    std::cout << "Unsorted data: ";
    for (int i = 0; i < vectorSize; i++) {
        std::cout << test[i] << " ";
    }
    std::cout << std::endl;
    PmergeMe::FJMI(test);

	return 0;
}
