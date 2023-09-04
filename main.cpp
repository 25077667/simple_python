#include <Simple_Python.hpp>
#include <iostream>

int main()
{
    // create a list
    auto list = std::make_shared<simple_python::List>();
    for (int i = 0; i < 10; ++i)
    {
        list->append(std::make_shared<simple_python::Integer>(i));
    }

    // create a dict
    auto dict = std::make_shared<simple_python::Dict>();
    for (int i = 0; i < 10; ++i)
    {
        dict->append(std::make_shared<simple_python::Pair>(
            std::make_shared<simple_python::Integer>(i),
            std::make_shared<simple_python::Integer>(i * i)));
    }

    // print the list
    std::cout << list->str() << std::endl;

    // print the dict
    std::cout << dict->str() << std::endl;

    // append the list to the dict
    dict->append(std::make_shared<simple_python::Pair>(
        std::make_shared<simple_python::Integer>(10),
        list));

    // print the dict
    std::cout << dict->str() << std::endl;

    return 0;
}