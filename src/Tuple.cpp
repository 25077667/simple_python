#include <Tuple.hpp>

std::string simple_python::Tuple::str() const
{
    std::string result = "(";
    for (auto it = value.begin(); it != value.end(); ++it)
    {
        result += (*it)->str();
        if (it != value.end() - 1)
            result += ", ";
    }
    result += ")";
    return result;
}

std::shared_ptr<simple_python::Object> simple_python::Tuple::operator[](int index)
{
    if (index < 0)
        index += (int)value.size();
    return value[index];
}

std::shared_ptr<simple_python::Object>
simple_python::Tuple::operator+(std::shared_ptr<simple_python::Object> other)
{
    auto result = std::make_shared<simple_python::Tuple>(value);
    result->value.push_back(other);
    return result;
}

bool simple_python::Tuple::operator==(const Object &other) const
{
    if (other.type() != type())
        return false;

    auto other_tuple = dynamic_cast<const Tuple *>(&other);
    if (value.size() != other_tuple->value.size())
        return false;

    for (int i = 0; i < value.size(); ++i)
        if (!(*value[i] == *other_tuple->value[i]))
            return false;

    return true;
}

const std::type_info &simple_python::Tuple::type() const
{
    return typeid(Tuple);
}