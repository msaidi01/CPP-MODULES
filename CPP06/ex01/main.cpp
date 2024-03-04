#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data = new Data;
    data->randomStr = "Hello World!";
    data->index = 42;
    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);
    std::cout << "data2->randomStr: " << data2->randomStr << std::endl;
    std::cout << "data2->index: " << data2->index << std::endl;
    delete data;
    return 0;
}
