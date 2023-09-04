#ifndef __SCC_SIMPLE_PYTHON_OBJECT_HPP__
#define __SCC_SIMPLE_PYTHON_OBJECT_HPP__

#include <string>
#include <typeinfo>

namespace simple_python
{
    struct Object
    {
        Object() = default;
        virtual ~Object() = default;
        virtual std::string str() const = 0;
        virtual bool operator==(const Object &other) const = 0;
        virtual bool operator!=(const Object &other) const;
        virtual const std::type_info &type() const = 0;
    };
} // namespace name

#endif // __SCC_SIMPLE_PYTHON_OBJECT_HPP__