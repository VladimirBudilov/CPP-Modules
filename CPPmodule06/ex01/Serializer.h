#ifndef C__CIRCLE_SERIALIZER_H
#define C__CIRCLE_SERIALIZER_H

#include "iostream"

struct Data {
	std::string s1;
};


class Serializer {
private:
	Serializer();
	virtual ~Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &stream, const Data &obj);

#endif //C__CIRCLE_SERIALIZER_H
