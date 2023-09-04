#ifndef __SCC_SIMPLE_PYTHON_LIST_HPP__
#define __SCC_SIMPLE_PYTHON_LIST_HPP__

#include <Object.hpp>
#include <string>
#include <vector>
#include <memory>

namespace simple_python
{
    struct List : Object
    {
        List() = default;
        List(std::vector<std::shared_ptr<Object>> value) : value(value) {}
        virtual std::string str() const override;
        virtual bool operator==(const Object &other) const override;
        virtual std::shared_ptr<Object> operator+(std::shared_ptr<Object> other);
        virtual std::shared_ptr<Object> operator[](int index);
        virtual void append(std::shared_ptr<Object> item);

    private:
        std::vector<std::shared_ptr<Object>> value;
    };
} // namespace name

#endif // __SCC_SIMPLE_PYTHON_LIST_HPP__