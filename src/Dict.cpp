#include <Dict.hpp>

std::string simple_python::Dict::str() const
{
    std::string result = "{";
    for (auto &pair : pairs)
    {
        result += pair->str() + ", ";
    }
    result += "}";
    return result;
}

bool simple_python::Dict::operator==(const Object &other) const
{
    auto other_dict = dynamic_cast<const Dict *>(&other);
    if (other_dict == nullptr)
        return false;

    if (pairs.size() != other_dict->pairs.size())
        return false;

    for (int i = 0; i < pairs.size(); ++i)
        if (*pairs[i] != *other_dict->pairs[i])
            return false;

    return true;
}

simple_python::Dict simple_python::Dict::operator+(const Dict &other) const
{
    std::vector<std::shared_ptr<Pair>> result_pairs = pairs;
    for (auto &pair : other.pairs)
    {
        result_pairs.push_back(pair);
    }
    return Dict(result_pairs);
}

std::shared_ptr<simple_python::Object> simple_python::Dict::operator[](const Object &key) const
{
    for (auto &pair : pairs)
    {
        if (*pair->first == key)
        {
            return pair->second;
        }
    }
    return nullptr;
}

void simple_python::Dict::append(std::shared_ptr<Pair> item)
{
    pairs.push_back(item);
}