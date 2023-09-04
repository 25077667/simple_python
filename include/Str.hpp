#ifndef __SCC_SIMPLE_PYTHON_STR_HPP__
#define __SCC_SIMPLE_PYTHON_STR_HPP__

#include <Object.hpp>
#include <string>
#include <memory>

namespace simple_python
{
    struct Str : Object
    {
        Str(std::string value) : value(value) {}
        virtual std::string str() const override;

        virtual std::shared_ptr<Object> operator[](int index);
        virtual std::shared_ptr<Object> operator+(std::shared_ptr<Object> other);
        virtual bool operator==(const Object &other) const override;

    private:
        std::string value;
    };
} // namespace name

#endif