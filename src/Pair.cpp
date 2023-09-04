#include <Pair.hpp>

std::string simple_python::Pair::str() const
{
    return first->str() + ": " + second->str();
}

bool simple_python::Pair::operator==(const Object &other) const
{
    auto other_pair = dynamic_cast<const Pair *>(&other);
    if (other_pair == nullptr)
    {
        return false;
    }
    return *first == *other_pair->first && *second == *other_pair->second;
}