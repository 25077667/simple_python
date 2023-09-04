#ifndef __SCC_SIMPLE_PYTHON_PAIR_HPP__
#define __SCC_SIMPLE_PYTHON_PAIR_HPP__

#include <object.hpp>
#include <memory>

namespace simple_python
{
    struct Pair : Object
    {
        Pair(std::shared_ptr<Object> first, std::shared_ptr<Object> second)
            : first(first), second(second) {}

        std::string str() const override;

        virtual bool operator==(const Object &other) const override;

        std::shared_ptr<Object> first;
        std::shared_ptr<Object> second;
    };
} // namespace name

#endif