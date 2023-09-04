#ifndef __SCC_SIMPLE_PYTHON_TUPLE_HPP__
#define __SCC_SIMPLE_PYTHON_TUPLE_HPP__

#include <Object.hpp>
#include <string>
#include <vector>
#include <memory>

namespace simple_python
{
    struct Tuple : Object
    {
        Tuple(std::vector<std::shared_ptr<Object>> value) : value(value) {}
        virtual std::string str() const override;

        virtual std::shared_ptr<Object> operator[](int index);
        virtual std::shared_ptr<Object> operator+(std::shared_ptr<Object> other);
        virtual bool operator==(const Object &other) const override;
        virtual const std::type_info &type() const override;

    private:
        std::vector<std::shared_ptr<Object>> value;
    };
} // namespace name

#endif // __SCC_SIMPLE_PYTHON_TUPLE_HPP__