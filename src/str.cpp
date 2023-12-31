#include <Str.hpp>

std::string simple_python::Str::str() const
{
    return value;
}

std::shared_ptr<simple_python::Object> simple_python::Str::operator[](int index)
{
    return std::make_shared<simple_python::Str>(std::string(1, value[index]));
}

std::shared_ptr<simple_python::Object> simple_python::Str::operator+(std::shared_ptr<simple_python::Object> other)
{
    return std::make_shared<simple_python::Str>(value + other->str());
}

bool simple_python::Str::operator==(const Object &other) const
{
    if (other.type() != type())
        return false;

    auto other_str = dynamic_cast<const Str *>(&other);
    return value == other_str->value;
}

const std::type_info &simple_python::Str::type() const
{
    return typeid(Str);
}