#include <Pair.hpp>

std::string simple_python::Pair::str() const
{
    return first->str() + ": " + second->str();
}

bool simple_python::Pair::operator==(const Object &other) const
{
    if (other.type() != type())
        return false;

    auto other_pair = dynamic_cast<const Pair *>(&other);
    return *first == *other_pair->first && *second == *other_pair->second;
}

const std::type_info &simple_python::Pair::type() const
{
    return typeid(Pair);
}