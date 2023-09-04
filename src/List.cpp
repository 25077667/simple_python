#include <List.hpp>

std::string simple_python::List::str() const
{
    std::string result = "[";
    for (auto it = value.begin(); it != value.end(); ++it)
    {
        result += (*it)->str();
        if (it != value.end() - 1)
        {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

std::shared_ptr<simple_python::Object> simple_python::List::operator[](int index)
{
    if (index < 0)
        index += (int)value.size();
    return value[index];
}

void simple_python::List::append(std::shared_ptr<simple_python::Object> item)
{
    value.push_back(item);
}

std::shared_ptr<simple_python::Object> simple_python::List::operator+(std::shared_ptr<simple_python::Object> other)
{
    auto other_list = dynamic_cast<List *>(other.get());
    if (other_list == nullptr)
        return nullptr;

    std::vector<std::shared_ptr<Object>> result = value;
    for (auto &item : other_list->value)
    {
        result.push_back(item);
    }
    return std::make_shared<List>(result);
}

bool simple_python::List::operator==(const Object &other) const
{
    auto other_list = dynamic_cast<const List *>(&other);
    if (other_list == nullptr)
        return false;

    if (value.size() != other_list->value.size())
        return false;

    for (int i = 0; i < value.size(); ++i)
        if (!(*value[i] == *other_list->value[i]))
            return false;

    return true;
}