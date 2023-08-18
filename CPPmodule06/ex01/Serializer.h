#ifndef C__CIRCLE_SERIALIZER_H
#define C__CIRCLE_SERIALIZER_H

#include "iostream"

struct Data {
	std::string s1;
	int n;
	std::string s2;
};


class Serializer {
private:
	Serializer();
	virtual ~Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
public:
	static void *serialize(void);
	static Data *deserialize(void *raw);
};


#endif //C__CIRCLE_SERIALIZER_H
