#include "Serializer.h"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

Serializer::~Serializer()
{
}


