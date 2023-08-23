#include "Array.h"

int main( void ) {
	Array<int> IntArr(0);
	Array<std::string> StrArr(0);
	std::cout << "IntArr.size(): " << IntArr.size() << std::endl;
	Array<int> intArr(5);
	Array<std::string> strArr(5);

	std::cout << "size: "<< intArr.size() << std::endl;
	for (size_t i = 0; i < intArr.size(); i++)
		intArr[i] = i;

	for (size_t i = 0; i < strArr.size(); i++)
		strArr[i] = std::to_string(i);

	std::cout << "intArr: ";
	for (size_t i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << std::endl;
	std::cout << std::endl;

	std::cout << "strArr: ";
	for (size_t i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << std::endl;

	try{
		std::cout << std::endl << "intArr[6]: " << intArr[6] << std::endl;
	}
	catch (std::exception &e) {

		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
