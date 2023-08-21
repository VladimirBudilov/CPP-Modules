#include "Serializer.h"

int main( int argc, char **argv) {

	if(argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	Data *data = new Data;
	data->s1 = argv[1];
	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);
	std::cout << data2->s1 << std::endl;
	delete data;
}
