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

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator<<(std::ostream &stream, const Data &obj)
{
	stream << "s1: " << obj.s1 << std::endl;
	return (stream);
}
