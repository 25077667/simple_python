#include <Integer.hpp>

std::string simple_python::Integer::str() const
{
    return std::to_string(value);
}

bool simple_python::Integer::operator==(const Object &other) const
{
    if (other.type() != type())
        return false;

    auto other_int = dynamic_cast<const Integer *>(&other);
    return value == other_int->value;
}

const std::type_info &simple_python::Integer::type() const
{
    return typeid(Integer);
}