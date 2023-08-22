#include "iter.h"

int main( void ) {



	{
		int arr[] = {1, 2, 3, 4, 5};
		iter(arr, 5, print);
		std::cout << std::endl;
		iter(arr, 5, increment);
		iter(arr, 5, print);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		const int arr[] = {1, 2, 3, 4, 5};
		iter(arr, 5, print<const int>);
		std::cout << std::endl;
		std::cout << std::endl;
		/*iter(arr, 5, increment);*/
	}
	{
		char arr[] = {'a', 'b', 'c', 'd', 'e'};
		iter(arr, 5, print);
		iter(arr, 5, increment);
		std::cout << std::endl;
		iter(arr, 5, print);
		std::cout << std::endl;
	}
	return 0;
}
