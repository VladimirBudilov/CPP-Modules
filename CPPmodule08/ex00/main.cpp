#include "easyfind.h"
#include "vector"

int main( void ) {
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> v = std::vector<int>(arr, arr + 5);
        try {
            std::cout << easyfind(v, 3) << std::endl;
            std::cout << easyfind(v, 7) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
	return 0;
}
