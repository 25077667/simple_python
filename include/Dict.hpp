#ifndef __SCC_SIMPLE_PYTHON_DICT_HPP__
#define __SCC_SIMPLE_PYTHON_DICT_HPP__

#include <Object.hpp>
#include <Pair.hpp>

#include <string>
#include <vector>
#include <memory>

namespace simple_python
{
    struct Dict : Object
    {
        Dict() = default;
        // it should be a pair of Object* and Object*
        Dict(std::vector<std::shared_ptr<Pair>> pairs)
            : pairs(pairs) {}

        virtual std::string str() const override;
        virtual bool operator==(const Object &other) const override;
        virtual Dict operator+(const Dict &other) const;
        virtual std::shared_ptr<Object> operator[](const Object &key) const;
        virtual void append(std::shared_ptr<Pair> item);
        virtual const std::type_info &type() const override;

    private:
        std::vector<std::shared_ptr<Pair>> pairs;
    };
} // namespace name

#endif // __SCC_SIMPLE_PYTHON_DICT_HPP__