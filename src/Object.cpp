#include <Object.hpp>

bool simple_python::Object::operator!=(const Object &other) const
{
    return !(*this == other);
}