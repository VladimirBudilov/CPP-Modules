#include "iter.h"
void increment(int &i) {
	i++;
}

void constIncrement(const int &i) {
	(void)i;
	std::cout << "sorry, i'm const" << std::endl;
}

int main( void ) {
	int arr[] = {1, 2, 3, 4, 5};
	//const int constArr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print<const int>);
	std::cout << std::endl;
	//iter(constArr, 5, print);
	std::cout << std::endl;
	iter(arr, 5, increment);
	std::cout << std::endl;
	iter(arr, 5, constIncrement);
	std::cout << std::endl;
	/*iter(arr, 5, print);
	std::cout << std::endl;
	iter(constArr, 5, print);*/
	return 0;
}
