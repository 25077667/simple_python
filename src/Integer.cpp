#include <Integer.hpp>

std::string simple_python::Integer::str() const
{
    return std::to_string(value);
}

bool simple_python::Integer::operator==(const Object &other) const
{
    auto other_int = dynamic_cast<const Integer *>(&other);
    if (other_int == nullptr)
    {
        return false;
    }
    return value == other_int->value;
}
