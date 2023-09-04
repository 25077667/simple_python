#ifndef __SCC_SIMPLE_PYTHON_INTEGER_HPP__
#define __SCC_SIMPLE_PYTHON_INTEGER_HPP__

#include <Object.hpp>
#include <string>

namespace simple_python
{
    struct Integer : Object
    {
        Integer(int value) : value(value) {}
        virtual std::string str() const override;
        virtual bool operator==(const Object &other) const override;
        virtual const std::type_info &type() const override;

    private:
        int value;
    };
} // namespace name

#endif // __SCC_SIMPLE_PYTHON_INTEGER_HPP__